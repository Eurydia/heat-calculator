class Material:
    def __init__(self, 
    name: str, 
    s_s: float, 
    s_l: float, 
    s_g: float, 
    l_sl: float, 
    l_lg: float, 
    m_p: float, 
    b_p: float):
        self.name = name
        self.specific_heat_cap_soild = round(s_s, 3)
        self.specific_heat_cap_liquid = round(s_l, 3)
        self.specific_heat_cap_gas = round(s_g, 3)
        self.latent_solid_to_liquid = round(l_sl, 3)
        self.latent_liquid_to_gas = round(l_lg, 3)
        self.melting_point = round(m_p, 3)
        self.boiling_point = round(b_p, 3)

    def calculate_heat(self, temp0: float, temp1: float, w: float):
        energy: float = 0
        temp0, temp1, w = map(lambda x: round(x, 3), (temp0, temp1, w))

        if temp0 == temp1:
            return 0
        elif temp1 > temp0:
            if temp0 < temp1 <= self.melting_point:
                return w * self.specific_heat_cap_soild * (temp1 - temp0)
            elif temp0 < self.melting_point < temp1:
                energy += w * ((self.specific_heat_cap_soild * (self.melting_point - temp0)) + self.latent_solid_to_liquid)
                temp0 = self.melting_point
            
            if self.melting_point <= temp0 < temp1 <= self.boiling_point:
                return energy + (w * self.specific_heat_cap_liquid * (temp1 - temp0))
            elif self.melting_point <= temp0 < self.boiling_point < temp1:
                energy += w * ((self.specific_heat_cap_liquid * (temp1 - temp0)) + self.latent_liquid_to_gas)
                temp0 = self.boiling_point
            
            if self.boiling_point <= temp0 < temp1:
                return energy + (w * self.specific_heat_cap_gas * (temp1 - temp0))
        
        elif temp1 < temp0:
            if temp0 > temp1 >= self.boiling_point:
                return w * self.specific_heat_cap_gas * (temp1 - temp0)
            elif temp0 > self.boiling_point > temp1:
                energy += w * ((self.specific_heat_cap_gas * (self.boiling_point - temp0)) + self.latent_liquid_to_gas)
                temp0 = self.boiling_point
            
            if self.boiling_point >= temp0 > temp1 >= self.melting_point:
                return energy + (w * self.specific_heat_cap_liquid * (temp1 - temp0))
            elif self.boiling_point >= temp0 > self.melting_point > temp1:
                energy += w * ((self.specific_heat_cap_liquid * (temp1 - temp0)) + self.latent_solid_to_liquid)
                temp0 = self.melting_point
            
            if self.melting_point >= temp0 > temp1:
                return energy + (w * self.specific_heat_cap_soild * (temp1 - temp0))

    def spec_listing(self):
        print(f"\n\tMaterial Name: {self.name}")
        print("\tSpecific Heat Capacity (kJ / kg * K): ")
        print(f"\t\tSoild: {self.specific_heat_cap_soild}")
        print(f"\t\tLiquid: {self.specific_heat_cap_liquid}")
        print(f"\t\tGas: {self.specific_heat_cap_gas}")
        print("\tLatent Heat Capacity (kJ / kg): ")
        print(f"\t\tSolid to Liquid: {self.latent_solid_to_liquid}")
        print(f"\t\tLiquid to Gas: {self.latent_solid_to_liquid}")
        print(f"\tMelting point: {self.melting_point}K")
        print(f"\tBoiling point: {self.boiling_point}K")


def type_guard(target_type: type, question: str):
    while True:
        try:
            ans = target_type(input(question))
        except ValueError:
            print(f'\nPlease enter a valid value ({target_type}).')
        else:
            return ans

def calculate_heat_question(material: Material):
    temp_init = type_guard(float, "\nEnter initial temperature (K) >> ")
    temp_final = type_guard(float, "\nEnter final temperature (K) >> ")
    weight = type_guard(float, "\nEnter material's weight (kg) >> ")
    energy = material.calculate_heat(temp_init, temp_final, weight)
    print(f"Initial temp -> {temp_init}K\nFinal temp -> {temp_final}K\nTemp diff -> {temp_final - temp_init}K\nWeight -> {weight}kg\nHeat gain/loss during this process is {energy}kJ")

    
def main():
    working = True
    materials = [Material('Water', 2.08, 4.18, 1.98, 333, 2256, 373.2, 273.2)]

    print("-"*15, "\nEnergy (Heat) Calculator\n", "-"*15, sep='\n')

    while(working):
        print("\n\tWould you like to")
        print("\n\t(1) Calculate using water")
        print("\n\t(2) Create new material entry")
        print("\n\t(3) Calculate using custom material")
        print("\n\t(4) Display saved materials")

        switch_choice = type_guard(int, '\nPick a choice! >> ')
        print('-'*15)
    
        if switch_choice == 1:
            calculate_heat_question(materials[0])
        
        elif switch_choice == 2:
            materials.append(Material(
                type_guard(float, "\nEnter Material's Name >> "),
                type_guard(float, "\nEnter Material's Specific Heat Capacity (kJ / kg * K):\n\tAs Soild >> "),
                type_guard(float, "\n\tAs Liquid >> "),
                type_guard(float, "\n\tAs Gas >> "),
                type_guard(float, "\nEnter Material's Latent Heat Capacity (kJ / kg):\n\tSolid to Liquid >> "),
                type_guard(float, "\nEnter initial temperature (K) >> "),
                type_guard(float, "\nEnter Material's Melting Point (K) >> "),
                type_guard(float, "\nEnter Material's Boiling Point (K) >> ")))
            print("\nNew Material added!")
        
        elif switch_choice == 3:
            for i, material in enumerate(materials):
                print(f'\t{i}. {material.name}')
            mat_selector = type_guard(int, "\nWhich material do you want to calculate with? >> ")
            while True:
                try:
                    calculate_heat_question(materials[mat_selector])
                except IndexError:
                    print('Please enter a valid value.')
                else:
                    break
        elif switch_choice == 4:
            for material in materials:
                material.spec_listing()
                print('-'*15)
	

if __name__ == '__main__':
    main()
    
                
