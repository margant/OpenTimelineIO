package io.opentimeline;

import io.opentimeline.opentimelineio.Any;
import io.opentimeline.opentimelineio.ErrorStatus;
import org.junit.jupiter.api.Test;

public class DummyTest {

    @Test
    public void test() {
        ErrorStatus e = new ErrorStatus();
        System.out.println(e.className);
    }

    @Test
    public void test2() throws InterruptedException{

        for (int i = 0 ; i < 1000; i++){
            Any any = OTIOFactory.getInstance().getAnyString("x");
            Thread.sleep(10);
            if (i%100 == 0) System.gc();
        }
        Thread.sleep(1000);
        System.gc();
        System.gc();
        System.gc();
        System.out.println("////////////////");
        OTIOFactory.getInstance().cleanUp();
        for (int i = 1000 ; i < 10000; i++){
            Any any = OTIOFactory.getInstance().getAnyString("x");
            Thread.sleep(10);
            if (i%100 == 0) System.gc();
        }
    }

}