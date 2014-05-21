# Violent Death
How do you know that your code is fault tolerant? How can you verify that it will not break in some terrible and irrecoverable way when something bad happens? This package will help you to simulate the most lethal events that your code can possibly face in it's life.

## Scenario
You want to test the fault tolerance of your code. You want to make sure that your code will always leave this world with things in a consistent state. The problem is that the kind of failure you can create inside PHP are
* **Soft:** they are more or less managed by the PHP interpreter
* **Predictable:** they are created by you in a synchronous way, in real life sh*t happens when you don't expect it, but you cannot simulate a failure say when you are executing a query or when you are making a request to a remote server

If you are asking yourself how you can manage this kind of failures then [graceful-death](https://github.com/gabrielelana/graceful-death) it's your answer

## Usage
```php
<?php

require __DIR__ . "/../vendor/autoload.php";

// The output will be something like:
//
// What is this? Should I drink it?
// There, I drank it, I will die eventually...
// Still there :-)
// Still there :-)
// …
// Still there :-)
// [1]    26584 segmentation fault (core dumped)  php examples/drink_poison.php

echo "What is this? Should I drink it?\n";
drink_poison($msToTakeEffect=500, $msToAgonizeAtMost=1000);
// Here we have created a background thread that will wait
// at least for 500ms and at most 1500ms before to cause
// an horrible death with a segmentation fault

echo "There, I drank it, I will die eventually...\n";
while(true) {
    echo "Still there :-)\n";
    usleep(50000);
}
```

## How Does It Work?
To create a segmentation fault we rely on a C extension. To eventually create a segmentation fault in the future (while the code is doing something else) we create a background thread that will wait some amount of time and then cause a segmentation fault.

## Gotcha
You need to be able to compile a PHP extension and you need the `pthread` library installed.

## Overview

### `drink_poison($msToTakeEffect, $msToAgonizeAtMost, $probabilityToDie)`
It will create a segmentation fault at least after `$msToTakeEffect` milliseconds and at most after `$msToTakeEffect + $msToAgonizeAtMost` milliseconds. This will happen asynchronously in background so that after this call the code can continue it's normal flow
* `int $msToTakeEffect`: How many milliseconds to wait before the poison takes effect
* `int $msToAgonizeAtMost`: At most how many milliseconds to wait before the poison will end your code. Default `0`
* `int $probabilityToDie`: The percentage of probability to die. An integer `1` and `100`. Default `100`

### `play_russian_roulette($probabilityToDie)`
### In Blast Extension: `die_violently_after($msToWait)`
### In Blast Extension: `die_violently($msToWait)`

## Install
You can comfortably install the package through composer
```sh
$ composer require "gabrielelana/violent-death"
```
But before you need to install the `blast` native extension

## Install Native Extension
To make sure to cause the most possible damage we need the most powerful and reliable weapon of self-destruction known to man: the C language
```sh
$ phphize
$ ./configure --with-pthread
$ make
$ sudo make install
```
Hopefully now the extension is compiled and installed. Now you need to enable it appending `extension=blast.so` in your `php.ini` file. Run the following commands, if you see the green bar then you are good to go
```sh
$ composer install
$ vendor/bin/phpunit
```

## Self-Promotion
If you like this project, then consider to:
* Star the repository on [GitHub](https://github.com/gabrielelana/graceful-death)
* Follow me on
  * [Twitter](http://twitter.com/gabrielelana)
  * [GitHub](https://github.com/gabrielelana)
