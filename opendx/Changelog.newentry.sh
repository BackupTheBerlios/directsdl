#!/bin/bash

#    libopendx-config a helper script for finding the libs and cflags
#    Copyright (C) 2004 Rene Roessler<rene@freshx.de>
#
#    This library is free software; you can redistribute it and/or
#    modify it under the terms of the GNU Lesser General Public
#    License as published by the Free Software Foundation; either
#    version 2.1 of the License, or (at your option) any later version.
#
#    This library is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
#    Lesser General Public License for more details.
#
#    You should have received a copy of the GNU Lesser General Public
#    License along with this library; if not, write to the Free Software
#    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
#
#    opendx is a wrapper, which provides DirectX functionality on top of the
#    Simple Direct Media Layer (SDL) library. Using opendx enables you to easily
#    port DirectX applications (for example games) to any platform supported
#    by the SDL library.

date=`date "+%Y%m%d"`
name=""
if [ -e ~/.opendx ]
then
  name=`cat ~/.opendx`
fi
echo ""
echo "Insert a new Changelog Entry:"
echo ""
echo "Your name[$name]:"
read namei

if [[ $namei != "" ]]
then
  name=$namei
fi

echo "The Changes you've made:"
read changes
echo ""
echo $name > ~/.opendx
echo $date - $name - \'$changes\' >> Changelog
echo $date - $name - \'$changes\'

