#!/bin/bash
#roscd reithner
roslaunch car_demo demo.launch &
xterm -e "tail -f ~/.ros/log/latest/forward_kinematics-7-stdout.log"
#sleep 2
wait
