#ifndef _tts_h_
#define _tts_h_

#include "common_headfile.h"

extern uint8_t sound[50];//测试使用外部数据。 内部测试使用
extern uint8_t len;
extern uint8_t tx_buffer_2[200]; //全局 发送语音缓存数组。
//--------------------------------------------------------------------------------------------------
//引脚配置
//--------------------------------------------------------------------------------------------------
#define TTS_UART           (UART_1)
#define TTS_TX             (UART1_TX_PA9)                                    // TTS RX引脚连接到单片机此
#define TTS_RX             (UART1_RX_PA10)                                   // TTS TX串口引脚
#define TTS_BUSY           (PA8)                                   					 // TTS BUSY引脚

void sound_spk(uint8_t len_2,uint8_t *sound_buffer);
void tts_init(void);

#endif 

