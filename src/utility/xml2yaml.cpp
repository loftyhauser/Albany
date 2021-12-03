#include <Teuchos_XMLParameterListCoreHelpers.hpp>
#include <Teuchos_YamlParameterListCoreHelpers.hpp>
#include <cassert>
#include <fstream>
#include <sstream>
#include <regex>

#ifdef ALBANY_DEBUG_BUILD
static bool ends_with(std::string const& s, std::string const& suffix) {
  if (s.length() < suffix.length()) return false;
  return 0 == s.compare(s.length() - suffix.length(), suffix.length(), suffix);
}
#endif

int main(int argc, char** argv) {
  for (int i = 1; i < argc; ++i) {
    std::string xmlFileName(argv[i]);
#ifdef ALBANY_DEBUG_BUILD
    assert(ends_with(xmlFileName, ".xml"));
#endif
    auto params = Teuchos::getParametersFromXmlFile(xmlFileName);
    auto baseName = xmlFileName.substr(0, xmlFileName.length() - 4);
    auto yamlFileName = baseName + ".yaml";
    std::ostringstream yamlStringStream;
    yamlStringStream << std::scientific << std::setprecision(17);
    Teuchos::writeParameterListToYamlOStream(*params, yamlStringStream);
    auto yamlString = yamlStringStream.str();
    /* replace references to other XML files with the YAML extension
       (e.g. material data files) */
    yamlString = std::regex_replace(yamlString, std::regex("\\.xml"), std::string(".yaml"));
    std::ofstream yamlFileStream(yamlFileName.c_str());
    assert(yamlFileStream.is_open());
    yamlFileStream << yamlString;
  }
}
