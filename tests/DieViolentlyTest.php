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

    public function testItWillRaiseSegmentationFault()
    {
        $descriptors = [
            0 => ['pipe', 'r'],
            1 => ['pipe', 'w'],
            2 => ['pipe', 'w'],
        ];
        $cwd = __DIR__ . '/../examples';
        $process = proc_open('php die_violently.php', $descriptors, $pipes, $cwd);
        $stdout = stream_get_contents($pipes[1]);
        $stderr = stream_get_contents($pipes[2]);
        fclose($pipes[1]);
        fclose($pipes[2]);
        $status = proc_get_status($process);
        $this->assertNotEquals(0, $status['exitcode']);
    }
}
