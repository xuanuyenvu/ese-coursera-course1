#include "data.h"
#include "memory.h"

uint8_t my_itoa(int32_t data, uint8_t *ptr, uint32_t base)
{
    uint8_t *start = ptr;
    uint8_t is_negative = 0;
    uint32_t udata;
    uint8_t digit;
    uint8_t length;

    if (data == 0)
    {
        *ptr = '0';
        ptr++;
        *ptr = '\0';
        return 2;
    }

    if ((data < 0) && (base == 10))
    {
        is_negative = 1;
        udata = (uint32_t)(-data);
    }
    else
    {
        udata = (uint32_t)data;
    }

    while (udata != 0)
    {
        digit = (uint8_t)(udata % base);
        if (digit < 10)
        {
            *ptr = digit + '0';
        }
        else
        {
            *ptr = (digit - 10) + 'A';
        }
        ptr++;
        udata = udata / base;
    }

    if (is_negative)
    {
        *ptr = '-';
        ptr++;
    }

    my_reverse(start, (size_t)(ptr - start));

    *ptr = '\0';
    ptr++;

    length = (uint8_t)(ptr - start);
    return length;
}

int32_t my_atoi(uint8_t *ptr, uint8_t digits, uint32_t base)
{
    int32_t result = 0;
    uint8_t is_negative = 0;
    uint8_t i = 0;
    uint8_t c;
    uint8_t value;

    if (*ptr == '-')
    {
        is_negative = 1;
        ptr++;
        i++;
    }

    for (; i < digits; i++)
    {
        c = *ptr;

        if ((c >= '0') && (c <= '9'))
        {
            value = c - '0';
        }
        else if ((c >= 'A') && (c <= 'F'))
        {
            value = (c - 'A') + 10;
        }
        else if ((c >= 'a') && (c <= 'f'))
        {
            value = (c - 'a') + 10;
        }
        else
        {
            break;
        }

        result = (result * (int32_t)base) + (int32_t)value;
        ptr++;
    }

    if (is_negative)
    {
        result = -result;
    }

    return result;
}