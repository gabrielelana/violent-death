<?php

require __DIR__ . "/../vendor/autoload.php";

// The output will be something like:
//
// > php examples/play_russian_roulette.php
// Ok, let's play
// Load... (;´_`)
// Click!... \*.*/
//
// > php examples/play_russian_roulette.php
// Ok, let's play
// Load... (;´_`)
// Click!... \*.*/
//
// > php examples/play_russian_roulette.php
// Ok, let's play
// Load... (;´_`)
// [1]    17098 segmentation fault (core dumped)  php examples/play_russian_roulette.php

echo "Ok, let's play\n";
echo "Load... (;´_`)\n";
play_russian_roulette(16);
echo "Click!... \*.*/\n";
