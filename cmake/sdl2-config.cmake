set(SDL2_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/include")

# Support both 32 and 64 bit builds
if (${CMAKE_SIZEOF_VOID_P} MATCHES 8)
  set(SDL2_LIBRARIES      "${CMAKE_CURRENT_LIST_DIR}/lib/x64/SDL2.lib;${CMAKE_CURRENT_LIST_DIR}/lib/x64/SDL2main.lib;")
  set(SDL2IMAGE_LIBRARIES "${CMAKE_CURRENT_LIST_DIR}/lib/x64/SDL2_image.lib")
  set(SDL2TTF_LIBRARIES   "${CMAKE_CURRENT_LIST_DIR}/lib/x64/SDL2_ttf.lib")
  set(SDL2AUDIO_LIBRARIES "${CMAKE_CURRENT_LIST_DIR}/lib/x64/SDL2_mixer.lib")
else ()
  set(SDL2_LIBRARIES      "${CMAKE_CURRENT_LIST_DIR}/lib/x86/SDL2.lib;${CMAKE_CURRENT_LIST_DIR}/lib/x86/SDL2main.lib")
  set(SDL2IMAGE_LIBRARIES "${CMAKE_CURRENT_LIST_DIR}/lib/x86/SDL2_image.lib")
  set(SDL2TTF_LIBRARIES   "${CMAKE_CURRENT_LIST_DIR}/lib/x86/SDL2_ttf.lib")
  set(SDL2AUDIO_LIBRARIES "${CMAKE_CURRENT_LIST_DIR}/lib/x86/SDL2_mixer.lib")
endif ()
set(SDL2_FOUND true)
string(STRIP "${SDL2_LIBRARIES}" SDL2_LIBRARIES)