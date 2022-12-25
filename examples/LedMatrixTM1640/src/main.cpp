/*
 * main.cpp
 * Copyright (C) 2022 Takashi Matsuoka <matsujirushi@live.jp>
 * MIT License
 */

////////////////////////////////////////////////////////////////////////////////
// Includes

#include <Arduino.h>
#include "TM1640.hpp"
#include "LedMatrix.hpp"
#include "LedMatrixAGFX.hpp"

////////////////////////////////////////////////////////////////////////////////
// Constants

static constexpr uint8_t TM1640_DIN_PIN = D10;
static constexpr uint8_t TM1640_SCLK_PIN = D8;

#if 0   // OSL641501

static const uint8_t TM1640_GRID_MAP[] =
{
    1,
    3,
    5,
    6,
    11,
    12,
    13,
    14,
    UINT8_MAX,
    UINT8_MAX,
    UINT8_MAX,
    UINT8_MAX,
    UINT8_MAX,
    UINT8_MAX,
    UINT8_MAX,
    UINT8_MAX,
};

static const uint8_t TM1640_ROW_MAP[] =
{
    6,
    5,
    7,
    4,
    0,
    1,
    2,
    3,
};

#endif  // OSL641501

#if 1   // LTP-12188M

static const uint8_t TM1640_GRID_MAP[] =
{
    1,
    3,
    5,
    6,
    11,
    12,
    13,
    14,
    0,
    2,
    4,
    15,
    10,
    9,
    8,
    7,
};

static const uint8_t TM1640_ROW_MAP[] =
{
    6,
    5,
    7,
    4,
    0,
    1,
    2,
    3,
};

#endif  // LTP-12188M

////////////////////////////////////////////////////////////////////////////////
// Variables

static TM1640 TM1640_{ TM1640_DIN_PIN, TM1640_SCLK_PIN, TM1640_GRID_MAP, TM1640_ROW_MAP };
static LedMatrix LedMatrix_{ TM1640_ };
static LedMatrixAGFX LedMatrixAGFX_{ LedMatrix_ };

////////////////////////////////////////////////////////////////////////////////
// setup and loop

void setup()
{
    Serial.begin(115200);
    delay(1000);
    Serial.println();
    Serial.println();

    TM1640_.begin();
    LedMatrix_.begin();
    TM1640_.SetBrightness(2);

    LedMatrixAGFX_.fillScreen(1);
    delay(200);
    LedMatrixAGFX_.fillScreen(0);
}

void loop()
{
    for (int y = 0; y < LedMatrixAGFX_.height(); ++y)
    {
        for (int x = 0; x < LedMatrixAGFX_.width(); ++x)
        {
            LedMatrixAGFX_.drawPixel(x, y, 1);
            delay(50);
        }
        for (int x = 0; x < LedMatrixAGFX_.width(); ++x)
        {
            LedMatrixAGFX_.drawPixel(x, y, 0);
            delay(50);
        }
        for (int x = 0; x < LedMatrixAGFX_.width(); ++x)
        {
            LedMatrixAGFX_.drawPixel(x, y, 2);
            delay(50);
        }
        for (int x = 0; x < LedMatrixAGFX_.width(); ++x)
        {
            LedMatrixAGFX_.drawPixel(x, y, 0);
            delay(50);
        }
        for (int x = 0; x < LedMatrixAGFX_.width(); ++x)
        {
            LedMatrixAGFX_.drawPixel(x, y, 3);
            delay(50);
        }
        for (int x = 0; x < LedMatrixAGFX_.width(); ++x)
        {
            LedMatrixAGFX_.drawPixel(x, y, 0);
            delay(50);
        }
    }
}

////////////////////////////////////////////////////////////////////////////////
