add_test([=[WindowTest.DrawTest]=]  /home/mapilsey/projects/rk2/build/tests/test_Window [==[--gtest_filter=WindowTest.DrawTest]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[WindowTest.DrawTest]=]  PROPERTIES WORKING_DIRECTORY /home/mapilsey/projects/rk2/build/tests SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  test_Window_TESTS WindowTest.DrawTest)
