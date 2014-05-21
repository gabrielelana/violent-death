# Violent Death
How do you know that your code is fault tolerant? How can you verify that it will not break in some terrible and irrecoverable way when something bad happens? This package will help you to simulate the most lethal events that your code can possibly face in it's life.

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

## Install
You can comfortably install the package through composer
```sh
$ composer require "gabrielelana/violent-death"
```
But you also need to install the native extension

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
