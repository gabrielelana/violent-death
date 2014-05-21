<?php

class GracefulDeathTest extends PHPUnit_Framework_TestCase
{
    public function testFunctionExists()
    {
        $this->assertTrue(function_exists('drink_poison'));
    }

    public function testTimeToTakeEffect()
    {
        $hasBeenCalled = false;
        drink_poison(100, 0, 100, function($msToWait) use(&$hasBeenCalled) {
            $hasBeenCalled = true;
            $this->assertEquals(100, $msToWait);
        });
        $this->assertTrue($hasBeenCalled);
    }

    public function testTimeToAgonizeShouldBeRandom()
    {
        $msOfAgony = [];
        $numberOfSamples = 10;
        foreach (range(1, $numberOfSamples) as $_) {
            $hasBeenCalled = false;
            drink_poison(100, 50, 100, function($msToWait) use(&$hasBeenCalled, &$msOfAgony) {
                $hasBeenCalled = true;
                $msOfAgony[] = $msToWait - 100;
            });
            $this->assertTrue($hasBeenCalled);
        }
        $this->assertGreaterThan(1, count(array_unique($msOfAgony)));
    }

    public function testProbabilityToDie()
    {
        $probabilityToDie = 30;
        $numberOfTimesHasBennCalled = 0;
        foreach (range(1, 100) as $_) {
            drink_poison(100, 0, $probabilityToDie,
                function() use(&$numberOfTimesHasBennCalled) {
                    $numberOfTimesHasBennCalled += 1;
                }
            );
        }
        $this->assertLessThan(50, $numberOfTimesHasBennCalled);
    }
}
