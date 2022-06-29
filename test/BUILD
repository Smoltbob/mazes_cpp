load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
  name = "test_cell",
  size = "small",
  srcs = ["test_cell.cpp"],
  deps = ["//:main",
		  "@com_google_googletest//:gtest_main"],
)

cc_test(
  name = "test_grid",
  size = "small",
  srcs = ["test_grid.cpp"],
  deps = ["//:main",
		  "@com_google_googletest//:gtest_main"],
)
