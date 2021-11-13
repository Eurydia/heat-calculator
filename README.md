# heat-calculator
A simple heat calculator that allows you to define your own materials.

This is the programm's main menu.
```
---------------------------

Energy(Heat) Calculator Program

---------------------------

    Would you like to

    (1) Calculate using water

    (2) Create new material entry

    (3) Calculate using custom material

    (4) Display saved materials

Pick a choice! >>
```
The programm comes default with one material which is water.
To calculate with water simply pick the first option.
```
Pick a choice! >> 1

---------------------------

Enter initial temperature (K) >> 57

Enter final temperature (K) >> 1500

Enter material's weight (kg) >> 23
```
There are three parameters required. The initial temperature of the material.
The final temperature of the material. And, The weight of the material itself.

Which yield the following output.
```
Heat (Q) created during this process is 125758 kJ!
```

The programm also allows you create and define your own material.
The material you created will be stored inside the programm.
But it will not persist once the programm is closed.

### Defining a custom meterial
To define a custom material typing in `2`
will bring up the material creation menu.
```
Enter Material's Name >> hmmm  

Enter Material's Specific Heat Capacity (kJ / kg * K): 

    As Soild >> 70

    As Liquid >> 70

    As Gas >> 70

Enter Material's Latent Heat Capacity (kJ / kg): 

    Solid to Liquid >> 70

    Liquid to Gas >> 70

Enter Material's Melting Point (K) >> 70

Enter Material's Boiling Point (K) >> 70
```
Once all the information is entered, the programm will add the new material to its list.
```
New Material added!

---------------------------
```
You can calculate using your custom material by typing `3`, then the index of the material you want to use.
```
Pick a choice! >> 3

---------------------------

Which material do you want to calculate with? >> 1
```
You can view all of your material by selecting `4`.
```
Pick a choice! >> 4

---------------------------

Material #1

    Material Name: hmmm
    Specific Heat Capacity (kJ / kg * K): 
        Soild: 70
        Liquid: 70
        Gas: 70
    Latent Heat Capacity (kJ / kg): 
        Solid to Liquid: 70
        Liquid to Gas: 70
     Melting point: 70 K
     Boiling point: 70 K
---------------------------
```
