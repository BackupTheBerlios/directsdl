#!/bin/bash
date=`date "+%Y%m%d"`
name=""
if [ -e ~/.sdldx ]
then
  name=`cat ~/.sdldx`
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
echo $name > ~/.sdldx
echo $date - $name - \'$changes\' >> Changelog
echo $date - $name - \'$changes\'

