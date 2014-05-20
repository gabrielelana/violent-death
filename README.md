# Violent Death
How do you know that your code is fault tolerant? How can you verify that it will not break in some terrible and irrecoverable way? This package will help you to simulate the most lethal events that your code can possibly encounter in it's life before it's too late

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
$ ./configure
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
