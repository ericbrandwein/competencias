#!/usr/bin/env fish

set CONTEST $argv[1]
mkdir $CONTEST && code $CONTEST && cf race $CONTEST && cd $CONTEST/a
