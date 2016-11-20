#include <iostream>

class Animal {
	
	public:
		Animal(char const *name_)
		{
			name = name_;
		}
		
		virtual char const *action() = 0;
		
		virtual void detectHuman()
		{
			std::cout << name << " detected a human and is " << action() << std::endl;
		}
	
	
	protected:
		const char *name;
};

class Bird: public Animal {
	
	public:
		Bird(char const *name_): Animal(name_) {}
		virtual char const *action()
		{
			return "flying away";
		}
};

class TameAnimal: public Animal {
	public:
		TameAnimal(char const *name_): Animal(name_) {}

		virtual void detectHuman()
		{
			std::cout << name << " is looking for cuddles while " << action() << std::endl;
		}
};

class Dog: public TameAnimal {
	public:
		Dog(char const *name_): TameAnimal(name_) {}

		virtual char const *action()
		{
			return "wagging its tail";
		}
};

class Cat: public TameAnimal {
	public:
		Cat(char const *name_): TameAnimal(name_) {}

		virtual char const *action()
		{
			return "purring loudly";
		}
};