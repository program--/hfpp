macro(target_compile_strict_cxx14 TARGET)
    target_compile_features(${TARGET} PUBLIC cxx_std_14)
    set_target_properties(${TARGET} PROPERTIES CXX_EXTENSIONS OFF)
endmacro()

macro(target_compile_options_ubsan TARGET)
    target_compile_options(${TARGET} PUBLIC "-fsanitize=undefined")
    target_link_options(${TARGET} PUBLIC "-fsanitize=undefined")
endmacro()

macro(target_compile_options_asan TARGET)
    target_compile_options(${TARGET} PUBLIC "-fsanitize=address")
    target_link_options(${TARGET} PUBLIC "-fsanitize=address")
endmacro()

macro(target_compile_options_lsan TARGET)
    target_compile_options(${TARGET} PUBLIC "-fsanitize=leak")
    target_link_options(${TARGET} PUBLIC "-fsanitize=leak")
endmacro()

function(target_compile_options_allsan TARGET)
    set(SAN_FLAG "-fsanitize=address,undefined,leak")
    target_compile_options(${TARGET} PUBLIC ${SAN_FLAG})
    target_link_options(${TARGET} PUBLIC ${SAN_FLAG})
endfunction()

macro(target_debug_extra TARGET)
    target_compile_options(${TARGET} PUBLIC $<IF:$<CONFIG:Debug>,-Wall -Wpedantic -Wextra,>)
endmacro()
