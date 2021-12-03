#include <Teuchos_XMLParameterListCoreHelpers.hpp>
#include <Teuchos_YamlParameterListCoreHelpers.hpp>
#include <cassert>

#ifdef ALBANY_DEBUG_BUILD
static bool ends_with(std::string const& s, std::string const& suffix) {
  if (s.length() < suffix.length()) return false;
  return 0 == s.compare(s.length() - suffix.length(), suffix.length(), suffix);
}
#endif

int main(int argc, char** argv) {
  for (int i = 1; i < argc; ++i) {
    std::string yamlFileName(argv[i]);
#ifdef ALBANY_DEBUG_BUILD
    assert(ends_with(yamlFileName, ".yaml"));
#endif
    auto params = Teuchos::getParametersFromYamlFile(yamlFileName);
    auto baseName = yamlFileName.substr(0, yamlFileName.length() - 5);
    auto xmlFileName = baseName + ".xml";
    Teuchos::writeParameterListToXmlFile(*params, xmlFileName);
  }
}
