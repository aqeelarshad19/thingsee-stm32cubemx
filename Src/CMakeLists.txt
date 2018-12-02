add_executable(firmware 
    ../startup_stm32l162xe.s
    main.c 
    stm32l1xx_hal_msp.c 
    system_stm32l1xx.c 
    stm32l1xx_it.c 
    usbd_desc.c 
    usb_device.c 
    usbd_cdc_if.c 
    usbd_conf.c
)
target_link_libraries(firmware c m nosys App u8g2 HAL UsbCore UsbClass)

firmware_size(firmware)
generate_object(firmware .bin binary)