<?php

class DieViolentlyTest extends PHPUnit_Framework_TestCase
{
    public function testExtensionIsLoaded()
    {
        $this->assertTrue(extension_loaded('blast'),
            "Seems like you don't have blast extension loaded\n" .
            "Look in the README.md how to compile and install it"
        );
    }

    public function testExtensionContainsDieViolentlyFunction()
    {
        $this->assertContains('die_violently', get_extension_funcs('blast'));
    }

    public function testExtensionContainsDieViolentlyAfterFunction()
    {
        $this->assertContains('die_violently_after', get_extension_funcs('blast'));
    }
}
