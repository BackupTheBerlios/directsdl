#!/usr/bin/perl    
#    opendx - A wrapper, which provides DirectX functionality on top of the SDL library
#    Copyright (C) 2004 Dominik Roessler <dominik@freshx.de>, Rene Roessler <rene@freshx.de>
#
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
#
#    opendx is a wrapper, which provides DirectX functionality on top of the
#    Simple Direct Media Layer (SDL) library. Using opendx enables you to easily
#    port DirectX applications (for example games) to any platform supported
#    by the SDL library.

# this perl script converts header files into dummy functions/classes and compiles them for testing.
# when it compiles without proplems, the dummy function/class will be printed to stdout.
# when it DON'T compiles, the name of the function will be written ro stdout(like this: //Error: function)

# user variables
# buildcmd: command to compile the file "tmp0815.c"
$buildcmd = "g++ `sdl-config --cflags` `pkg-config --cflags gtk+-2.0` -O3 tmp0815.c `sdl-config --libs` `pkg-config --libs gtk+-2.0` -shared -fPIC -o tmp0815.a";

if($ARGV[0] eq "")
{
print "\nYou have given no arguments to this Script!\nrun header2dummy.pl like this: \"/usr/bin/perl header2dummy.pl [headerfile] > [dummy c file]\"\n\n";
exit 0;
}

# boolean variables
$comment = 0;
$class = 0;
$preclass = 0;
$compile = 0;

# the header files
$init = '
#include <stdio.h>
#include "'.$ARGV[0].'"
';

undef $/;
$file = <>;

print $init;

# convert '\r\n' to '\n'
@lines = split(/[\n\r]/,$file);


foreach(@lines)
{
        # remove whitespaces
	$_ =~ s/\s+/ /g;
	$_ =~ s/^\s*//g;	
	$_ =~ s/\s*$//g;	

        # comments 
	if($_ =~ /\s*\/\*\s*/)
	{
		$comment = 1;
	}

	if($comment && $_ =~ /\s*\*\/\s*/)
	{
		$comment = 0;
	}

	$_ =~ s/\/\*.*?(\*\/)?//g;
	$_ =~ s/\/\/.*//;
	$_ =~ s/\*\///g;

	if($_ =~ /^#/)
	{
		$line = "";
	}elsif($comment)
	{
		$line .= "";
	}else
	{
	# if it's not a comment
	        # remove newlines
		$_ =~ s/[\r\n]//g;
		$_ =~ s/[\n]//g;
		if($line)
		{
			$line .= " ".$_;
		}else
		{
			$line = $_;
		}

		# class
		if($line =~ /(.*?)\s*class\s*([a-zA-Z0-9_]+)/ && $1 ne typedef)
		{
			$classname = $2;
			$preclass = 1;
			$out="";
		}

		if($line =~ /\s*{\s*/ && $preclass)
		{
			$preclass = 0;
			$class = 1;
		}
		
		# method
		if($line =~ /\s*([a-zA-Z0-9_]+)\s([a-zA-Z0-9_]+)\s*\((.*?)\);/ && $class)
		{
			$ret = $1;
			$method = $2;
			$params = $3;
			$out .= "
$ret $classname\:\:$method($params)
{
return ($ret)'\\0';
};
			";
		}
		# constructor/destructor
		elsif($line =~ /\s*([a-zA-Z0-9_~]+)\s*\((.*?)\);/ && $class)
		{
			$name = $1;
			$params = $2;
			$out .= "
$classname\:\:$name($params){};
			";
		}
		
		if($class && $line =~ /\s*}\s*;\s*/)
		{
			$class = 0;
			$classname = "";
			$compile = 1;
		}

		# function
		if($line =~ /([a-zA-Z0-9_]+)\s+([a-zA-Z0-9_]+)\s*\((.*?)\);/ && $1 ne "typedef" && !$class && !$preclass)
		{
			$out="";
			$ret = $1;
			$fkt = $2;
			$params = $3;

			if($ret && $fkt && $params)
			{
				$fkt =~ s/\s//g;
				$ret =~ s/\s//g;

				if(!$fkts{$fkt}) 
				{
					$fkts{$fkt} = 1;

					@params = split(/,/, $params);

					$out .= "
$ret $fkt($params)
{
printf(\"The function $fkt is not yet implemented.\");
return ($ret)'\\0';
}
";
					$compile=1;
				}
			}
		}
		# compile the generated code
		if($compile)
		{
			open(TMP, ">tmp0815.c");
			print TMP $init.$out;
			close(TMP);
			$err = "";
			
			open(CC, $buildcmd);

			while(<CC>)
			{
				$err .= $_;
			}
			close(CC);
				
			system("rm tmp0815.*");
			if($err =~ /error:/i)
			{
				print "//ERROR: $fkt\n";
				$out="";
			}else
			{
				print $out;
				$out="";
			}
		}
		$line = "";
	}
}
