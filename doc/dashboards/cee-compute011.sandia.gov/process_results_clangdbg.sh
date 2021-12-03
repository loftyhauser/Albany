
cd /scratch/albany
grep "Test   #" nightly_log_clangdbg-albany.txt >& results0
grep "Test  #" nightly_log_clangdbg-albany.txt >& results1 
cat results0 results1 >& results11
grep "Test #" nightly_log_clangdbg-albany.txt >& results0
cat results11 results0 >& results1
grep " tests failed" nightly_log_clangdbg-albany.txt >& results2 
cat results1 results2 >& results3
grep "Total Test" nightly_log_clangdbg-albany.txt >& results4
cat results3 results4 >& results5
echo "" >> results5
grep "(Failed)" nightly_log_clangdbg-albany.txt >& results6
cat results5 results6 >& results7
grep "\*Timeout" nightly_log_clangdbg-albany.txt >& results8
cat results7 results8 >& results_clangdbg-albany
echo "" >> results_clangdbg-albany
echo "The Albany CDash site can be accessed here: https://sems-cdash-son.sandia.gov/cdash/index.php?project=Albany" >> results_clangdbg-albany
echo "" >> results_clangdbg-albany 
rm results0 results1 results11 results2 results3 results4 results5 results6 results7 results8
source send_email_clangdbg.sh
