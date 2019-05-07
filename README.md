# android_groups_generator

Generate Android system users/groups for Linux system.

Uses headers from https://github.com/aosp-mirror/platform_system_core or https://android.googlesource.com/platform/system/core.git/

Only one include file is used, containing Android user IDs and their names.

platform_system_core_android-24 is included as an example of this file from Android 7. You can point your buld to other include directory with file from specific Android version.
