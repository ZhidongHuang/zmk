/*
 * Copyright (c) 2020 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#include <init.h>
#include <device.h>
#include <devicetree.h>

#include <logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

#include <drivers/display.h>
#include <lvgl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ZMK_DISPLAY_NAME CONFIG_LVGL_DISPLAY_DEV_NAME

LV_FONT_DECLARE(inconsolata);

static struct device *display;

static lv_obj_t *screen;
// static lv_style_t mystyle;

int zmk_display_init() {
    lv_obj_t *hello_world_label;
    lv_obj_t *count_label;
    lv_obj_t *num_label;
    lv_obj_t *logo_img;
    unsigned int num = 99;
    char strnum[10]={0};
    LOG_DBG("");
    printf ("BBBBBBBBBBBBBBBZMK_DISPLAY_NAME  %s\n",ZMK_DISPLAY_NAME);
    display = device_get_binding(ZMK_DISPLAY_NAME);
    if (display == NULL) {
        LOG_ERR("Failed to find display device");
        return -EINVAL;
    }
    // LV_ALIGN_CENTER

    screen = lv_obj_create(NULL, NULL);
    lv_scr_load(screen);

    num_label = lv_label_create(lv_scr_act(), NULL);
    lv_label_set_text(num_label,"99");
    lv_obj_align(num_label, NULL, LV_ALIGN_IN_LEFT_MID    , 0, 30);

    hello_world_label = lv_label_create(lv_scr_act(), NULL);
    lv_label_set_text(hello_world_label, "ZMK v0.1.0");
    lv_obj_align(hello_world_label, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 0);
    count_label = lv_label_create(lv_scr_act(), NULL);
    lv_label_set_text(count_label, CONFIG_ZMK_KEYBOARD_NAME);
    lv_obj_align(count_label, NULL, LV_ALIGN_IN_BOTTOM_MID, 0, 0);


    // logo_img = lv_label_create(lv_scr_act(), NULL);
    // // lv_style_set_text_font(&mystyle, LV_STATE_DEFAULT, &inconsolata);
    // lv_label_set_text(logo_img, "");
    // lv_obj_align(logo_img, NULL, LV_ALIGN_IN_BOTTOM_MID, 0, 0);

    logo_img = lv_label_create(lv_scr_act(), NULL);
    lv_label_set_text(logo_img, LV_SYMBOL_BLUETOOTH );
    lv_obj_align(logo_img, NULL, LV_ALIGN_IN_RIGHT_MID, 0, 0);

    // logo_img = lv_img_create(lv_scr_act(), NULL);
    // lv_img_set_src(logo_img, LV_SYMBOL_BLUETOOTH );
    // lv_obj_align(logo_img, NULL, LV_ALIGN_OUT_RIGHT_MID, 0, 0);

    lv_task_handler();
    display_blanking_off(display);
    // k_sleep(K_MSEC(4000));

    // num_label = lv_label_create(lv_scr_act(), NULL);
    // hello_world_label = lv_label_create(lv_scr_act(), NULL);
    // count_label = lv_label_create(lv_scr_act(), NULL);
    while(1){
        lv_tick_inc(50);
        sprintf(strnum, "%d", num);
        // lv_label_set_text(num_label, strnum);
        // lv_obj_align(num_label, NULL, LV_ALIGN_IN_LEFT_MID , 0, 0);
		// lv_task_handler();
		// k_sleep(K_MSEC(1000));
		num--;
        if (num==0)
            num = 99;

        // screen = lv_obj_create(screen, screen);
        lv_scr_load(screen);

        // num_label = lv_label_create(lv_scr_act(), NULL);
        // lv_style_set_text_font(&my_style, LV_STATE_DEFAULT, &lv_font_montserrat_28);
        lv_label_set_text(num_label,strnum);
        // lv_obj_align(num_label, NULL, LV_ALIGN_IN_LEFT_MID    , 0, 0);

        // hello_world_label = lv_label_create(lv_scr_act(), NULL);
        // lv_label_set_text(hello_world_label, "ZMK v0.1.0");
        // lv_obj_align(hello_world_label, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 0);

        // count_label = lv_label_create(lv_scr_act(), NULL);
        // lv_label_set_text(count_label, CONFIG_ZMK_KEYBOARD_NAME);
        // lv_obj_align(count_label, NULL, LV_ALIGN_IN_BOTTOM_MID, 0, 0);
        lv_tick_inc(50);
        lv_task_handler();
        display_blanking_off(display);
        k_sleep(K_MSEC(50));
    }

    return 0;
}



void zmk_display_task_handler() {
    // char strnum[10]={};
    
    // // itoa(num,strnum,10);
    // sprintf(strnum,"%d",num);

    // lv_label_set_text(num_label, strnum);
    // num ++;
    // if (num>=100)
    //     num =1;
    // lv_tick_inc(10);
    lv_task_handler();
    // display_blanking_off(display);
    k_sleep(K_MSEC(10));
}
