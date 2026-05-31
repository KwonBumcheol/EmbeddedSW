#!/bin/bash
                
TEST_GPIO=17   # GPIO 17 제어

function setTEST { # GPIO 값 변경
    if [ "$1" == "1" ]; then
        sudo pinctrl set $TEST_GPIO dh # HIGH 출력
    else
        sudo pinctrl set $TEST_GPIO dl # LOW 출력
    fi
}

if [ $# -ne 1 ]; then # 인자의 개수($#)가 정확히 1개가 아닐경우
    echo "Usage: bashTEST [setup|on|off|status|close]"
    exit 2
fi
echo "The TEST command that was passed is: $1"
if [ "$1" == "setup" ]; then
    echo "Setting GPIO $TEST_GPIO as output"
    sudo pinctrl set $TEST_GPIO op
elif [ "$1" == "on" ]; then
    echo "Turning ON"
    setTEST 1
elif [ "$1" == "off" ]; then
    echo "Turning OFF"
    setTEST 0
elif [ "$1" == "status" ]; then
    pinctrl $TEST_GPIO
elif [ "$1" == "close" ]; then
    echo "Reset to input mode"
    sudo pinctrl set $TEST_GPIO ip
fi