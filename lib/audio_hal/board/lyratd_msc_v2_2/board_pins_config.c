#ifdef CONFIG_ESP_LYRATD_MSC_V2_2_BOARD
#include "esp_log.h"
#include "driver/gpio.h"
#include "board_pins_config.h"

static const char *TAG = "LYRAT_V4_2";

esp_err_t get_i2c_pins(i2c_port_t port, i2c_config_t *i2c_config)
{
    BOARD_PARAMETER_CHECK(TAG, i2c_config, return ESP_FAIL);
    if (port == I2C_NUM_0 || port == I2C_NUM_1) {
        i2c_config->sda_io_num = GPIO_NUM_18;
        i2c_config->scl_io_num = GPIO_NUM_23;
    } else {
        i2c_config->sda_io_num = -1;
        i2c_config->scl_io_num = -1;
        ESP_LOGE(TAG, "i2c port %d is not supported", port);
        return ESP_FAIL;
    }
    return ESP_OK;
}

esp_err_t get_i2s_pins(i2s_port_t port, i2s_pin_config_t *i2s_config)
{
    BOARD_PARAMETER_CHECK(TAG, i2s_config, return ESP_FAIL);
    if (port == I2S_NUM_0 || port == I2S_NUM_1) {
        i2s_config->bck_io_num = GPIO_NUM_5;
        i2s_config->ws_io_num = GPIO_NUM_25;
        i2s_config->data_out_num = GPIO_NUM_26;
        i2s_config->data_in_num = GPIO_NUM_35;
    } else {
        memset(i2s_config, -1, sizeof(i2s_pin_config_t));
        ESP_LOGE(TAG, "i2s port %d is not supported", port);
        return ESP_FAIL;
    }
    return ESP_OK;
}

esp_err_t get_spi_pins(spi_bus_config_t *spi_config, spi_device_interface_config_t *spi_device_interface_config)
{
    BOARD_PARAMETER_CHECK(TAG, spi_config, return ESP_FAIL);
    spi_config->mosi_io_num = GPIO_NUM_33;
    spi_config->miso_io_num = GPIO_NUM_27;
    spi_config->sclk_io_num = GPIO_NUM_32;
    spi_config->quadwp_io_num = -1;
    spi_config->quadhd_io_num = -1;

    spi_device_interface_config->spics_io_num = GPIO_NUM_0;

    return ESP_OK;
}

// sdcard

int8_t get_sdcard_intr_gpio(void)
{
    return SDCARD_INTR_GPIO;
}

int8_t get_sdcard_open_file_num_max(void)
{
    return SDCARD_OPEN_FILE_NUM_MAX;
}

// input-output pins

int8_t get_headphone_detect_gpio(void)
{
    return HEADPHONE_GPIO;
}

int8_t get_pa_enable_gpio(void)
{
    return PA_ENABLE_GPIO;
}

// adc button

int8_t get_adc_detect_gpio(void)
{
    return ADC_DETECT_GPIO;
}

int8_t get_input_rec_id(void)
{
    return BUTTON_REC_ID;
}

int8_t get_input_mode_id(void)
{
    return BUTTON_MODE_ID;
}

int8_t get_input_play_id(void)
{
    return BUTTON_PLAY_ID;
}

int8_t get_input_set_id(void)
{
    return BUTTON_SET_ID;
}

int8_t get_input_volup_id(void)
{
    return BUTTON_VOLUP_ID;
}

int8_t get_input_voldown_id(void)
{
    return BUTTON_VOLDOWN_ID;
}

// board related

int8_t get_reset_codec_gpio(void)
{
    return CODEC_RESET_GPIO;
}

int8_t get_reset_board_gpio(void)
{
    return DSP_RESET_GPIO;
}

#endif
