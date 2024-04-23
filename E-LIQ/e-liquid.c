#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void BaseAndLiqMix(int BaseQuantity, int BaseStrength, int EliquidQuantity, int EliquidStrength, float *QuantityResult, float *StrengthResult);
void LiqAndLiqMix(int BaseQuantity, int BaseStrength, int EliquidQuantity, int EliquidStrength, float *QuantityResult, float *StrengthResult);
void VariableResetState(int Choice, int Base_Quantity, int Base_Strength, int Eliquid_Quantity , int Eliquid_Strength, float Quantity_Result, float Strength_Result);
int RESET = 0;
int main()
{
	/* Used for the switch case and choice if user wants to mix 2 e liquids or a base and e liquid */
	int Choice;
	/* Quantity of the base */
	int Base_Quantity;
	/* Base strength */
	int Base_Strength;
	/* E-liquid quantity */
	int Eliquid_Quantity;
	/* E-liquid nicotine strength */
	int Eliquid_Strength;
	/* The result of the quantity of the mixture */
	float Quantity_Result;
	/* The result of the strength of the mixture */
	float Strength_Result;

	printf("Enter all values in ml\n");
	printf("Choose 1 to mix Base and Nicotine\n");
	printf("Choose 2 to mix E-liquid and E-liquid\n");
	printf("Choose 3 to exit\n");
	printf("(1)(Base & Nicotine) , (2)(E-liq & E-liq) , (3)(exit) :");
	scanf("%d", &Choice);

	if(Choice <= 3)
	{
	switch(Choice)
	{
	/* First option is e-liquid mixed with base */
	case 1 :
		printf("Enter Base quantity: ");
		scanf(" %d", &Base_Quantity);
		Base_Strength = 0;
		printf("Enter nic-shot / e-liquid quantity: ");
		scanf(" %d", &Eliquid_Quantity);
		printf("Enter nic-shot / e-liquid strength: ");
		scanf(" %d", &Eliquid_Strength);
		BaseAndLiqMix(Base_Quantity, Base_Strength, Eliquid_Quantity, Eliquid_Strength, &Quantity_Result, &Strength_Result);
		printf("Mixture quantity: %fml || Mixture strength: %fmg", Quantity_Result, Strength_Result);
		/*VariableResetState(Choice, Base_Quantity, Base_Strength, Eliquid_Quantity, Eliquid_Strength, Quantity_Result, Strength_Result);*/
		break;
		/* Second option is e-liquid mixed with e-liquid  */
	case 2 :
		printf("Enter the first e-liquid quantity: ");
		scanf(" %d", &Base_Quantity);
		printf("Enter the first e-liquid strength: ");
		scanf(" %d", &Base_Strength);
		printf("Enter the second e-liquid quantity: ");
		scanf(" %d", &Eliquid_Quantity);
		printf("Enter the second e-liquid strength: ");
		scanf(" %d", &Eliquid_Strength);
		LiqAndLiqMix(Base_Quantity, Base_Strength, Eliquid_Quantity, Eliquid_Strength, &Quantity_Result, &Strength_Result);
		printf("Mixture quantity: %fml || Mixture strength: %fmg", Quantity_Result, Strength_Result);
		break;
		/* Third option is to exit the application */
	case 3 :
		exit(0);
		break;
	}
	/*Wait 10 seconds and go back to main state and ask for options again*/
	}
	else
	{
		printf("Invalid option selected");
		sleep(3);
		exit(0);
	}
}

/* Base and liquid mixing  */
void BaseAndLiqMix(int Base_Quantity, int Base_Strength, int Eliquid_Quantity, int Eliquid_Strength, float *Quantity_Result, float *Strength_Result)
{
	/* Checking for NULL pointers */
	if(NULL != Strength_Result && NULL != Quantity_Result)
	{
		/* Calculation for the Nicotine Results and Quantity of the e-liquid */
		*Strength_Result =  ((float)Eliquid_Strength) / (((float)Base_Quantity)/((float)Eliquid_Quantity));
		*Quantity_Result = Base_Quantity + Eliquid_Quantity;
	}
	else
	{
		printf("Invalid Input!");
	}
}

/* Liquid and liquid mixing */
void LiqAndLiqMix(int Base_Quantity, int Base_Strength, int Eliquid_Quantity, int Eliquid_Strength, float *Quantity_Result, float *Strength_Result)
{
	/* Checking for NULL pointers */
	if(NULL != Strength_Result && NULL != Quantity_Result)
	{
		/* Calculation for the Nicotine results and Quantity of the e-liquid */
		*Strength_Result = ((float)Base_Strength + (float)Eliquid_Strength) / 2;
		*Quantity_Result = Base_Quantity + Eliquid_Quantity;
	}
	else
	{
		printf("Invalid Input!");
	}
}

/*work in progress to reset all of the counters and go back to the start state*/
void VariableResetState(int Choice, int Base_Quantity, int Base_Strength,int Eliquid_Quantity, int Eliquid_Strength, float Quantity_Result, float Strength_Result)
{
   Choice = RESET;
   Base_Quantity = RESET;
   Eliquid_Strength = RESET;
   Quantity_Result = RESET;
   Strength_Result = RESET;
}
