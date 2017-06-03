#!/bin/sh
#===============================================================================
#
#  S95runapp.sh
#
#  Copyright (C) 2008 by Digi International Inc.
#  All rights reserved.
#
#  This program is free software; you can redistribute it and/or modify it
#  under the terms of the GNU General Public License version 2 as published by
#  the Free Software Foundation.
#
#
#  !Revision:    $Revision: 1.9 $:
#  !Description: Run application defined in uboot environment
#
#===============================================================================

set -e

[ -e "/etc/profile" ] && source /etc/profile

if [ "${1}" != "start" ]; then
	exit 0
fi

if ! ENV="$(ubootenv -p 'start_app start_app_args' 2>/dev/null)"; then
	echo "[ FAIL ] S95runapp.sh: ubootenv unable to read NVRAM"
	exit 1
fi

export TSLIB_TSDEVICE="/dev/input/ts0"
export QWS_MOUSE_PROTO="tslib:/dev/input/ts0"
cat /etc/profile.d/touchscreen.sh
source /etc/profile.d/touchscreen.sh

modprobe gpio
cd /dev/gpio
mknod 1 c 240 1
mknod 9 c 240 9
mknod 106 c 240 106
mknod 107 c 240 107
mknod 108 c 240 108
mknod 109 c 240 109
mknod 175 c 240 175
mknod 176 c 240 176
mknod 198 c 240 198

##start_app="$(echo ${ENV} | sed -n -e '/start_app=/{s/start_app=\([^[:space:]]*\) *.*/\1/;p}')"
##start_app_args="$(echo ${ENV} | sed -n -e '/start_app_args=/{s/.*start_app_args=\([^[:space:]]*\)/\1/;p}')"

if [ "x${start_app}" != "x" ]; then
	## If var is empty or the app is not found in rootfs, then exit.
	if [ -x "${start_app}" ]; then
		## The applications exists, so run it.
		[ -z "${quietboot}" ] && echo "Start ${start_app}... "
		${start_app} ${start_app_args} &
	else
		echo "Application not executable: ${start_app}"
		exit 1
	fi
fi



exit 0

