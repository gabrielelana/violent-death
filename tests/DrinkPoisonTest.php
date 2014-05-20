<?php

class GracefulDeathTest extends PHPUnit_Framework_TestCase
{
    public function testFunctionExists()
    {
        $this->assertTrue(function_exists('drink_poison'));
    }
}
