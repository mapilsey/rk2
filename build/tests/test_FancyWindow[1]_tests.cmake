add_test([=[FancyWindowTest.DrawTest]=]  /home/mapilsey/projects/rk2/build/tests/test_FancyWindow [==[--gtest_filter=FancyWindowTest.DrawTest]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[FancyWindowTest.DrawTest]=]  PROPERTIES WORKING_DIRECTORY /home/mapilsey/projects/rk2/build/tests SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  test_FancyWindow_TESTS FancyWindowTest.DrawTest)
