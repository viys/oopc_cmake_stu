#include "stdio.h"
#include "animal.h"
#include "money.h"
#include "my_config.h"

ANIMAL *Cat = NULL;
ANIMAL_IMPLEMENTS *cat = NULL;

ANIMAL *Mouse = NULL;
ANIMAL_IMPLEMENTS *mouse = NULL;

MONEY* MoneyA = NULL;
MONEY_IMPLEMENTS* moneyA = NULL;

MONEY* MoneyB = NULL;
MONEY_IMPLEMENTS* moneyB = NULL;

int main(void)
{
    printf("Version: %s\n", CONFIG_FIRMWARE_VERSION);

    Animal_Attribute attr1 = {
        .name = "cat",
        .age = 4,
        .sound = "mimi"
    };

    Cat = ANIMAL_CTOR();
    Cat->init(Cat, &attr1);
    cat = (ANIMAL_IMPLEMENTS*)Cat;
    cat->get_name(cat);
    cat->get_age(cat);
    cat->show_sound(cat);

    Animal_Attribute attr2 = {
        .name = "mouse",
        .age = 2,
        .sound = "xixi"
    };

    Mouse = ANIMAL_CTOR();
    Mouse->init(Mouse, &attr2);
    mouse = (ANIMAL_IMPLEMENTS*)Mouse;
    mouse->get_name(mouse);
    mouse->get_age(mouse);
    mouse->show_sound(mouse);
    
    Money_Attribute attr3 = {
        .amount = 10
    };

    Money_Attribute attr4 = {
        .amount = 5
    };

    MoneyA = MONEY_CTOR();
    MoneyA->init(MoneyA, &attr3);
    moneyA = (MONEY_IMPLEMENTS*)MoneyA;

    MoneyB = MONEY_CTOR();
    MoneyB->init(MoneyB, &attr4);
    moneyB = (MONEY_IMPLEMENTS*)MoneyB;

    CLASS_LOG("MoneyA\n");
    moneyA->get_amount(moneyA);
    moneyA->comparison(moneyA, moneyB);

    CLASS_LOG("MoneyB\n");
    moneyB->get_amount(moneyB);
    moneyA->comparison(moneyB, moneyA);
}