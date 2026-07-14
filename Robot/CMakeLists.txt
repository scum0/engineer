
# =========================================================================
# 2. 声明Hero目标文件库（OBJECT库，仅编译目标文件不链接，保留原工程逻辑）
# =========================================================================
add_library(Engineer OBJECT)

# ===================== 所有源文件（严格匹配文件名/大小写/路径） =====================
    target_sources(Engineer
            PRIVATE
            # === Arm ===

            pyro_mission_planer.cpp
            pyro_init_thread.cpp
    )

    # 针对 Gimbal 的特殊头文件包含
    target_include_directories(Engineer
            PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/Arm
            ${CMAKE_CURRENT_SOURCE_DIR}/Communication
            ${CMAKE_CURRENT_SOURCE_DIR}/Communication
            ${CMAKE_CURRENT_SOURCE_DIR}
    )
    target_compile_definitions(PYRo PUBLIC
            DR16_UART=PYRO_UART5
            VT03_UART=PYRO_UART1
            AUTOAIM_UART=PYRO_UART7
    )


# ===================== 链接依赖库（保留原工程依赖，可按需增删） =====================
target_link_libraries(Engineer
        PUBLIC
        stm32cubemx
        dsppp_lib
        PYRo
)
