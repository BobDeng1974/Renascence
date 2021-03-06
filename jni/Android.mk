# Copyright (C) 2009 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)
define all-cpp-files
$(shell find $(LOCAL_PATH)/../src -name "*.cpp")
endef
define all-c-files
$(shell find $(LOCAL_PATH)/../src -name "*.c")
endef

LOCAL_MODULE    := libGP
LOCAL_CFLAGS    := -Werror -O3
LOCAL_CFLAGS    += -DBUILD_FOR_ANDROID
LOCAL_CPP_FEATURES := rtti
LOCAL_SRC_FILES := $(call all-cpp-files) \
                   $(call all-c-files) \
				   ../third/tinyxml/tinystr.cpp \
				   ../third/tinyxml/tinyxml.cpp \
				   ../third/tinyxml/tinyxmlerror.cpp \
				   ../third/tinyxml/tinyxmlparser.cpp

LOCAL_C_INCLUDES += $(LOCAL_PATH)/../include/
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../third/tinyxml
LOCAL_LDLIBS    := -lz -lm -llog

include $(BUILD_SHARED_LIBRARY)

