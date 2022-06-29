load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "new_git_repository")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

http_archive(
		name = "com_google_googletest",
		urls = ["https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip"],
		strip_prefix = "googletest-609281088cfefc76f9d0ce82e1ff6c30cc3591e5",
		)

http_archive(
		name = "rules_cc",
		urls = ["https://github.com/bazelbuild/rules_cc/archive/40548a2974f1aea06215272d9c2b47a14a24e556.zip"],
		strip_prefix = "rules_cc-40548a2974f1aea06215272d9c2b47a14a24e556",
		)

new_git_repository(
		name = "opencv",
		remote = "https://github.com/opencv/opencv",
		build_file = "@//:opencv.BUILD",
		tag = "3.1.0",
		)

http_archive(
		name = "libpng",
		build_file = "@//:libpng.BUILD",
		strip_prefix = "libpng-1.2.57",
		urls = [
				"https://mirror.bazel.build/github.com/glennrp/libpng/archive/v1.2.57.tar.gz",
				"https://github.com/glennrp/libpng/archive/v1.2.57.tar.gz",
				],
		)

http_archive(
        name = "zlib",
	build_file = "@//:zlib.BUILD",
        strip_prefix = "zlib-cacf7f1d4e3d44d871b605da3b647f07d718623f",
        urls = [
            "https://mirror.bazel.build/github.com/madler/zlib/archive/cacf7f1d4e3d44d871b605da3b647f07d718623f.tar.gz",
            "https://github.com/madler/zlib/archive/cacf7f1d4e3d44d871b605da3b647f07d718623f.tar.gz",
        ],
    )
