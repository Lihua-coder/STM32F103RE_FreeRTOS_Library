#include "device_tts.h"

uint8_t sun_chick = 0; //临时定义全局 长度数据变量


uint8_t sound[50] = {0};//测试使用外部数据。 内部测试使用



uint8_t tx_buffer_2[200] = {0x7e,0x00,0x00}; //全局 发送语音缓存数组。

uint8_t len= sizeof(sound) / sizeof(sound[0]);

uint8_t len_num = sizeof(sound);

static uint8_t calculate_checksum(uint8_t *data, uint8_t length) 
{
    uint16_t sum = 0; // 使用16位累加器，防止溢出
		uint8_t i = 0;
    for (i = 0; i < length; i++) {
        sum += data[i];
    }
    // 返回8位校验值（可以取低8位或进行其他处理）
    return (uint8_t)(sum & 0xFF);
}

/*播放GB2312的标准数据，传入的参数
len_2：接收播放语音字节的长度
sound_buffer：指向接收语音的数组。
*/
void sound_spk(uint8_t len_2,uint8_t *sound_buffer)
{
	
	
	
	tx_buffer_2[0] = 0x7e;
	tx_buffer_2[1] = 0x00;
	tx_buffer_2[2] = len_2+9;
	tx_buffer_2[3] = 0x01;
	tx_buffer_2[4] = 0x00;
	tx_buffer_2[5] = 0x03;
	tx_buffer_2[6] = 0x03;
	tx_buffer_2[7] = 0xe8;
	tx_buffer_2[8] = len_2;
	
	sun_chick = tx_buffer_2[2];
	memcpy(&tx_buffer_2[9],sound_buffer,len_2);
	
	tx_buffer_2[sun_chick] = calculate_checksum(&tx_buffer_2[1],sun_chick-1);
	
	tx_buffer_2[sun_chick+1] = 0xef;
	
}



void tts_init(void)
{
  uart_init(TTS_UART, 9600, TTS_TX, TTS_RX);
	gpio_init(TTS_BUSY, GPI_PULL_DOWN, 0);
}




