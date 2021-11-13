#include <iostream>
#include <stdio.h>

using std::string, std::cin, std::cout, std::endl;

class Material {
	private:
		string Name;

		float Specific_s;
		float Specific_l;
		float Specific_g;

		float Latent_sl;
		float Latent_lg;

		float Melting;
		float Boiling;

	public:
		void create_material() {
			cout << "\nEnter Material's Name >> ";
			cin >> Name;

			cout << "\nEnter Material's Specific Heat Capacity (kJ / kg * K): " << endl;

			cout << "\n\tAs Soild >> ";
			cin >> Specific_s;

			cout << "\n\tAs Liquid >> ";
			cin >> Specific_l;

			cout << "\n\tAs Gas >> ";
			cin >> Specific_g;

			cout << "\nEnter Material's Latent Heat Capacity (kJ / kg): " << endl;

			cout << "\n\tSolid to Liquid >> ";
			cin >> Latent_sl;

			cout << "\n\tLiquid to Gas >> ";
			cin >> Latent_lg;

			cout << "\nEnter Material's Melting Point (K) >> ";
			cin >> Melting;

			cout << "\nEnter Material's Boiling Point (K) >> ";
			cin >> Boiling;
		}

		void get_material(string n, float s1, float s2, float s3, float l1, float l2, float m, float b) {
			Name = n;

			Specific_s = s1;
			Specific_l = s2;
			Specific_g = s3;

			Latent_sl = l1;
			Latent_lg = l2;

			Melting = m;
			Boiling = b;
		}

		void specs_listing() {
			cout << "\n\tMaterial Name: " << Name << endl;

			cout << "\tSpecific Heat Capacity (kJ / kg * K): " << endl;
			cout << "\t\tSoild: " << Specific_s << endl;
			cout << "\t\tLiquid: " << Specific_l << endl;
			cout << "\t\tGas: " << Specific_g << endl;

			cout << "\tLatent Heat Capacity (kJ / kg): " << endl;
			cout << "\t\tSolid to Liquid: " << Latent_sl << endl;
			cout << "\t\tLiquid to Gas: " << Latent_lg << endl;

			cout << "\t Melting point: " << Melting << " K" << endl;
			cout << "\t Boiling point: " << Boiling << " K" << endl;
		}

		float get_melting() {
			return Melting;
		}

		float get_boiling() {
			return Melting;
		}

		float get_specific_s() {
			return Specific_s;
		}

		float get_specific_l() {
			return Specific_l;
		}

		float get_specific_g() {
			return Specific_g;
		}

		float get_latent_sl() {
			return Latent_sl;
		}

		float get_latent_lg() {
			return Latent_lg;
		}
};

float calculateHeat(float t0, float t1, float w, Material m) {
	float a = 0, b = 0, c = 0, d = 0, e = 0;
	float t = t0;

	if (t <= t1 && t < m.get_melting()) {
		
		if (t1 <= m.get_melting()) {
			a = w * m.get_specific_s() * (t1 - t);
		}

		else {
			a = w * m.get_specific_s() * (m.get_melting() - t);
			t = m.get_melting();
		}
	}

	if (t <= t1 && t == m.get_melting()) {
		b = w * m.get_latent_sl();
	}

	if (t <= t1 && t < m.get_boiling() && t == m.get_melting()) {

		if (t1 <= m.get_boiling()) {
			c = w * m.get_specific_l() * (t1 - t);
		}

		else {
			c = w * m.get_specific_s() * (m.get_boiling() - t);
			t = m.get_boiling();
		}
	}

	if (t < t1 && t == m.get_boiling() && m.get_melting() < t1) {
		d = w * m.get_latent_lg();
	}

	if (t < t1 && t1 > m.get_boiling()) {
		e = w * m.get_specific_g() * (t1 - t); 
	}

	return a + b + c + d + e;

}

int main() {
	int switch_case;
	int index = 0;
	int material_selector;

	float temp_init;
	float temp_fin;
	float weight;

	Material def_mat1;
	Material saved[64];

	cout << "---------------------------" << endl;
	cout << "\nEnergy(Heat) Calculator Program\n" << endl;
	cout << "---------------------------" << endl;

	while (1) {

		cout << "\n\tWould you like to" << endl;
		cout << "\n\t(1) Calculate using water" << endl;
		cout << "\n\t(2) Create new material entry" << endl;
		cout << "\n\t(3) Calculate using custom material" << endl;
		cout << "\n\t(4) Display saved materials" << endl;

		cout << "\nPick a choice! >> ";
		cin >> switch_case;

		cout << "\n---------------------------" << endl;

		switch (switch_case) {
			case 1:
		
				def_mat1.get_material("Water", 2.08, 4.18, 1.98, 333, 2256, 273.2, 373.2);

				cout << "\nEnter initial temperature (K) >> ";
				cin >> temp_init;

				cout << "\nEnter final temperature (K) >> ";
				cin >> temp_fin;

				cout << "\nEnter material's weight (kg) >> ";
				cin >> weight;

				cout << "\nHeat (Q) created during this process is ";
				cout << calculateHeat(temp_init, temp_fin, weight, def_mat1);
				cout << " kJ!" << endl;
			break;

			case 2:
			
				saved[index].create_material();
				cout << "\nNew Material added!\n" << endl;
				index ++;

			break;

			case 3:
				if (index == 0) {
					cout << "\nNo saved element to choose from. Please create a new element.\n" << endl;
					break;
				}

				cout << "\nWhich material do you want to calculate with? >> ";
				cin >> material_selector;

				cout << "\nEnter initial temperature (K) >> ";
				cin >> temp_init;

				cout << "\nEnter final temperature (K) >> ";
				cin >> temp_fin;

				cout << "\nEnter material's weight (kg) >> ";
				cin >> weight;

				cout << "\nHeat (Q) created during this process is ";
				cout << calculateHeat(temp_init, temp_fin, weight, saved[material_selector]);
				cout << " kJ!" << endl;
			break;

			case 4:
				if (index == 0){	
					cout << "\nNo material to display\n" << endl;
				}
				
				else {
					for(int g = 0; g < index; g++) {
						cout << "\nMaterial #" << g << endl;
						saved[g].specs_listing();
					}
				}
			break;
		}
		cout << "---------------------------" << endl;
	}
}