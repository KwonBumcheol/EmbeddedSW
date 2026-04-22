#!/bin/bash
                
TEST_GPIO=17   

function setTEST {
    if [ "$1" == "1" ]; then
        sudo pinctrl set $TEST_GPIO dh
    else
        sudo pinctrl set $TEST_GPIO dl
    fi
}

if [ $# -ne 1 ]; then
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