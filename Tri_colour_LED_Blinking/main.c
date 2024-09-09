#include <msp430.h>

void delay_ms(unsigned int ms);

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer

    // Set P2.1, P2.3, and P2.5 as output (RGB LED)
    P2DIR |= BIT1 | BIT3 | BIT5;

    while (1) {
        // Red
        P2OUT |= BIT1;
        P2OUT &= ~(BIT3 | BIT5);
        delay_ms(750);

        // Green
        P2OUT |= BIT3;
        P2OUT &= ~(BIT1 | BIT5);
        delay_ms(750);

        // Blue
        P2OUT |= BIT5;
        P2OUT &= ~(BIT1 | BIT3);
        delay_ms(750);

        // Red + Green (Yellow)
        P2OUT |= BIT1 | BIT3;
        P2OUT &= ~BIT5;
        delay_ms(750);

        // Red + Blue (Magenta)
        P2OUT |= BIT1 | BIT5;
        P2OUT &= ~BIT3;
        delay_ms(750);

        // Green + Blue (Cyan)
        P2OUT |= BIT3 | BIT5;
        P2OUT &= ~BIT1;
        delay_ms(750);

        // Red + Green + Blue (White)
        P2OUT |= BIT1 | BIT3 | BIT5;
        delay_ms(750);
    }
}

// Delay function (approximate, based on clock frequency of ~1MHz)
void delay_ms(unsigned int ms) {
    while (ms--) {
        __delay_cycles(1000); // 1ms delay at 1MHz clock
    }
}
