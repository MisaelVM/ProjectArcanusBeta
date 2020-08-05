#pragma once

#include <iostream>
#include <math.h>
#include <string>
#include <cstdlib>
#include <time.h>
namespace rpg
{
    class state
    {
        std::string name;
        int stat_affect;
        int power;
        int turn;
    public:
        state();

        void set_state(std::string, int, int, int);
        void set_turn();
        void show_data();
        friend class stats;
        friend class equipment;
        friend class ability;
        friend class character;
        friend class enemy;
        friend class consumible;
    };

    state::state()
    {
        name = "normal";
        stat_affect = 0;
        power = 0;
        turn = 0;
    }


    void state::set_state(std::string name, int stat_effect, int power, int turn)
    {
        this->name = name;
        this->stat_affect = stat_effect;
        this->power = power;
        this->turn = turn;
    }

    void state::set_turn()
    {
        if (turn > 0)
            turn--;
        if (turn == 0)
        {
            name = "normal";
            stat_affect = 0;
            power = 0;
        }
    }
    void state::show_data()
    {
        std::cout << "State:   \n\n name:" << name << "\n";
        std::cout << "power: " << power << "\n";
        std::cout << "turn: " << turn << "\n";
    }

    class table_element
    {
        std::string* element_list;
        int _size;
        int** array_weakness;
    public:
        table_element(std::string[], int);
        void set_debilities(std::string, std::string, std::string);
        std::string get_element(int);
        int _s_w_n(std::string, std::string);
        void show_table();
        ~table_element();
    };


    class stats
    {
        std::string* stadistic_name;
        int* value;
        int _size;
        state* _state;
    public:
        stats();
        stats(std::string[], int[], int);
        stats(const stats&);
        std::string get_stat_name(int);
        int get_stat_value(int);
        int get_size();
        void set_value(int[]);
        void set_v_value(int, int);
        void set_name(std::string[]);
        void sum_value(int, int);
        void show_data();
        void set_state(std::string, int, int, int);
        void pass_turn();
        void remove_state(std::string);
        void show_state();
        ~stats();
        friend class character;
        friend class enemy;
    };
    class level
    {
        int act_level;
        float experience;
        float necesary_exp;
        float total_exp;
        int max_level;
        float constant;
    public:
        level();
        level(int, float, float, float, int, float);
        level(level&);
        float get_total_exp();
        int get_level();
        float get_experience();
        float get_necesary_experience();
        int get_max_level();
        float get_constant();
        void set_necesary_experience();
        void add_exp(float);
        void level_up(float);
        void validation_system();
        friend class character;
    };

    class ability
    {
        std::string name;
        //std::string state;
        state _state;
        bool phisical_magical;
        int power;
        std::string element;
        std::string state_name;
        int consume;
    public:
        ability();
        ability(ability&);
        ability(std::string, int, table_element&, int, std::string, int, std::string, int, int, int, bool);
        std::string get_name();
        //std::string get_state();
        bool get_phisical_magical();
        void modify_abilities(ability&);
        int get_power();
        int get_consume();
        std::string get_element();
        std::string get_state_name();
        void show_data();
        friend class character;
        friend class state;
        friend class enemy;
    };
    /*
    class item
    {
    protected:

        std::string name;
        std::string description;
    public:
        item();
        item(std::string, std::string);
        virtual std::string get_name();
        virtual std::string get_description();
        virtual void show_data();
    };
    */
    class item
    {
    protected:

        std::string name;
        std::string description;
    public:
        item();
        item(std::string, std::string);
        virtual std::string get_name();
        virtual std::string get_description();
        virtual void show_data();
    };

    class equipment : public item
    {
    protected:
        int num;
        std::string* names;
        int* improve;
        std::string element;
        state special;
    public:
        equipment();
        equipment(int, std::string*, int*, std::string, std::string, std::string);
        equipment(int, std::string*, int*, std::string, std::string, int, int, int, std::string, std::string);
        std::string get_element();
        int get_num();
        state& get_special();
        void show_data();
        friend class character;
    };

    equipment::equipment() : special()
    {
        num = 0;
        names = nullptr;
        improve = nullptr;
        element = "empty";
    }
    equipment::equipment(int num, std::string* stats, int* improvement, std::string element, std::string name, std::string description) : special(), item(name, description)
    {
        this->num = num;
        this->element = element;
        names = new std::string[num];
        improve = new int[num];
        for (int i = 0; i < num; i++)
        {
            names[i] = stats[i];
            improve[i] = improvement[i];
        }
    }

    equipment::equipment(int num, std::string* stats, int* improvement, std::string element, std::string state_name, int stat_eff, int pow, int turns, std::string n, std::string d) : special(), item(n, d)
    {
        this->num = num;
        this->element = element;
        names = new std::string[num];
        improve = new int[num];
        for (int i = 0; i < num; i++)
        {
            names[i] = stats[i];
            improve[i] = improvement[i];
        }
        special.set_state(state_name, stat_eff, pow, turns);
    }
    std::string equipment::get_element()
    {
        return element;
    }

    state& equipment::get_special()
    {
        return special;
    }

    void equipment::show_data()
    {
        std::cout << "name: " << name << std::endl;
        std::cout << "description: " << description << std::endl;
        std::cout << "improve stats:\n\n";
        for (int i = 0; i < num; i++)
            std::cout << names[i] << ": " << improve[i] << "\n";
        std::cout << "element: " << element << "\n";
        std::cout << "state: " << special.name;
    }

    int equipment::get_num()
    {
        return num;
    }

    class costume : public equipment
    {
    protected:
        std::string type;
        bool equip;
    public:
        costume();
        costume(int, std::string*, int*, std::string, std::string, std::string);
        costume(int, std::string*, int*, std::string, std::string, int, int, int, std::string, std::string);
        std::string get_type() { return type; };
        bool get_equip() { return equip; };
        void equiped() { equip = true; };
        void unequiped() { equip = false; };
        friend class inventory;
    };


    costume::costume() : equipment()
    {
        equip = false;
        type = "null";
    }
    costume::costume(int num, std::string* stats, int* improvement, std::string element, std::string n, std::string d) : equipment(num, stats, improvement, element, n, d)
    {
        equip = false;
        type = "null";
    }
    costume::costume(int num, std::string* stats, int* improvement, std::string element, std::string state_name, int stat_eff, int pow, int turns, std::string n, std::string d) : equipment(num, stats, improvement, element, state_name, stat_eff, pow, turns, n, d)
    {
        equip = false;
        type = "null";
    }

    class head :public costume
    {
    public:
        head() : costume() { type = "head"; };
        head(int num, std::string* stats, int* improvement, std::string element, std::string n, std::string d) : costume(num, stats, improvement, element, n, d) { type = "head"; };
        head(int num, std::string* stats, int* improvement, std::string element, std::string state_name, int stat_eff, int pow, int turns, std::string n, std::string d) : costume(num, stats, improvement, element, state_name, stat_eff, pow, turns, n, d)
        {
            type = "head";
        }
        void show()
        {
            show_data();
            std::cout << "\ntype: " << type;
        }
    };

    class legs :public costume
    {
    public:
        legs() : costume() { type = "legs"; };
        legs(int num, std::string* stats, int* improvement, std::string element, std::string n, std::string d) : costume(num, stats, improvement, element, n, d) { type = "legs"; };
        legs(int num, std::string* stats, int* improvement, std::string element, std::string state_name, int stat_eff, int pow, int turns, std::string n, std::string d) : costume(num, stats, improvement, element, state_name, stat_eff, pow, turns, n, d)
        {
            type = "legs";
        }
        void show()
        {
            show_data();
            std::cout << "\ntype: " << type;
        }
    };

    class armor :public costume
    {
    public:
        armor() : costume() { type = "armor"; };
        armor(int num, std::string* stats, int* improvement, std::string element, std::string n, std::string d) : costume(num, stats, improvement, element, n, d) { type = "armor"; };
        armor(int num, std::string* stats, int* improvement, std::string element, std::string state_name, int stat_eff, int pow, int turns, std::string n, std::string d) : costume(num, stats, improvement, element, state_name, stat_eff, pow, turns, n, d)
        {
            type = "armor";
        }
        void show()
        {
            show_data();
            std::cout << "\ntype: " << type;
        }
    };

    class accesory :public costume
    {
    public:
        accesory() : costume() { type = "accesory"; };
        accesory(int num, std::string* stats, int* improvement, std::string element, std::string n, std::string d) : costume(num, stats, improvement, element, n, d) { type = "accesory"; };
        accesory(int num, std::string* stats, int* improvement, std::string element, std::string state_name, int stat_eff, int pow, int turns, std::string n, std::string d) : costume(num, stats, improvement, element, state_name, stat_eff, pow, turns, n, d)
        {
            type = "accesory";
        }
        void show()
        {
            show_data();
            std::cout << "\ntype: " << type;
        }
    };

    class weapon : public equipment
    {
    protected:
        std::string type;
        bool equip;
    public:
        weapon();
        weapon(int, std::string*, int*, std::string, std::string, std::string);
        weapon(int, std::string*, int*, std::string, std::string, int, int, int, std::string, std::string);
        std::string get_type() { return type; };
        bool get_equip() { return equip; };
        void equiped() { equip = true; };
        void unequiped() { equip = false; };
        friend class inventory;
    };

    weapon::weapon() : equipment()
    {
        equip = false;
        type = "null";
    }
    weapon::weapon(int num, std::string* stats, int* improvement, std::string element, std::string n, std::string d) : equipment(num, stats, improvement, element, n, d)
    {
        equip = false;
        type = "null";
    }
    weapon::weapon(int num, std::string* stats, int* improvement, std::string element, std::string state_name, int stat_eff, int pow, int turns, std::string n, std::string d) : equipment(num, stats, improvement, element, state_name, stat_eff, pow, turns, n, d)
    {
        equip = false;
        type = "null";
    }

    class shield :public weapon
    {
    public:
        shield() : weapon() { type = "head"; };
        shield(int num, std::string* stats, int* improvement, std::string element, std::string n, std::string d) : weapon(num, stats, improvement, element, n, d) { type = "head"; };
        shield(int num, std::string* stats, int* improvement, std::string element, std::string state_name, int stat_eff, int pow, int turns, std::string n, std::string d) : weapon(num, stats, improvement, element, state_name, stat_eff, pow, turns, n, d)
        {
            type = "shield";
        }
        void show()
        {
            show_data();
            std::cout << "\ntype: " << type;
        }
    };

    class sword :public weapon
    {
    public:
        friend class inventory;
        sword() : weapon() { type = "sword"; };
        sword(int num, std::string* stats, int* improvement, std::string element, std::string n, std::string d) : weapon(num, stats, improvement, element, n, d) { type = "sword"; };
        sword(int num, std::string* stats, int* improvement, std::string element, std::string state_name, int stat_eff, int pow, int turns, std::string n, std::string d) : weapon(num, stats, improvement, element, state_name, stat_eff, pow, turns, n, d)
        {
            type = "sword";
        }
        void show()
        {
            show_data();
            std::cout << "\ntype: " << type;
        }
    };

    class spear :public weapon
    {
    public:
        spear() : weapon() { type = "spear"; };
        spear(int num, std::string* stats, int* improvement, std::string element, std::string n, std::string d) : weapon(num, stats, improvement, element, n, d) { type = "spear"; };
        spear(int num, std::string* stats, int* improvement, std::string element, std::string state_name, int stat_eff, int pow, int turns, std::string n, std::string d) : weapon(num, stats, improvement, element, state_name, stat_eff, pow, turns, n, d)
        {
            type = "spear";
        }
        void show()
        {
            show_data();
            std::cout << "\ntype: " << type;
        }
    };

    class axe :public weapon
    {
    public:
        axe() : weapon() { type = "axe"; };
        axe(int num, std::string* stats, int* improvement, std::string element, std::string n, std::string d) : weapon(num, stats, improvement, element, n, d) { type = "axe"; };
        axe(int num, std::string* stats, int* improvement, std::string element, std::string state_name, int stat_eff, int pow, int turns, std::string n, std::string d) : weapon(num, stats, improvement, element, state_name, stat_eff, pow, turns, n, d)
        {
            type = "axe";
        }
        void show()
        {
            show_data();
            std::cout << "\ntype: " << type;
        }
    };

    class bow :public weapon
    {
    public:
        bow() : weapon() { type = "bow"; };
        bow(int num, std::string* stats, int* improvement, std::string element, std::string n, std::string d) : weapon(num, stats, improvement, element, n, d) { type = "bow"; };
        bow(int num, std::string* stats, int* improvement, std::string element, std::string state_name, int stat_eff, int pow, int turns, std::string n, std::string d) : weapon(num, stats, improvement, element, state_name, stat_eff, pow, turns, n, d)
        {
            type = "bow";
        }
        void show()
        {
            show_data();
            std::cout << "\ntype: " << type;
        }
    };

    class crosier :public weapon
    {
    public:
        crosier() : weapon() { type = "crosier"; };
        crosier(int num, std::string* stats, int* improvement, std::string element, std::string n, std::string d) : weapon(num, stats, improvement, element, n, d) { type = "crosier"; };
        crosier(int num, std::string* stats, int* improvement, std::string element, std::string state_name, int stat_eff, int pow, int turns, std::string n, std::string d) : weapon(num, stats, improvement, element, state_name, stat_eff, pow, turns, n, d)
        {
            type = "crosier";
        }
        void show()
        {
            show_data();
            std::cout << "\ntype: " << type;
        }
    };

    class knife :public weapon
    {
    public:
        knife() : weapon() { type = "knife"; };
        knife(int num, std::string* stats, int* improvement, std::string element, std::string n, std::string d) : weapon(num, stats, improvement, element, n, d) { type = "knife"; };
        knife(int num, std::string* stats, int* improvement, std::string element, std::string state_name, int stat_eff, int pow, int turns, std::string n, std::string d) : weapon(num, stats, improvement, element, state_name, stat_eff, pow, turns, n, d)
        {
            type = "knife";
        }
        void show()
        {
            show_data();
            std::cout << "\ntype: " << type;
        }
    };
    /*
    class weapon : public item
    {
        std::string weapon_type;
        std::string element;
        int* buff_debuff;
        int _size;
    public:
        weapon();
        weapon(weapon&);
        weapon(std::string, std::string, std::string, table_element&, int, int[], int);
        std::string get_name();
        std::string get_decription();
        std::string get_weapon_type();
        std::string get_element();
        void modify(weapon&);
        void modify_unequip();
        int get_buff_debuff(int);
        int get_size();
        void show_data();
        friend class character;
        ~weapon();
    };*/



    

    class role
    {
        std::string name, code_stats, code_weapons;
        ability* hab;
        level level_of_role;
        int* level_to_use;
        int _size;
    public:
        role();
        role(role&);
        role(std::string, std::string, std::string, ability[], level, int[], int);
        std::string get_name();
        std::string get_code_stats();
        std::string get_code_weapons();
        int get_size();
        level get_lvl();
        void copy(role&);
        int get_level_to_use(int);
        ability& get_ability(int);
        int get_code_role(int);
        void add_level(float);
        void display_habs();
        int get_level();
        void show_data();
        ~role();
        friend class character;
    };



    class character
    {
        std::string name;
        std::string state;
        std::string code_state;
        stats _stats;
        stats act_stats;
        int turn_state;
        int size_of_roles;
        level _level;
        role* roles;
        int* point_role;
        weapon** weapons;
        costume** costumes;
        int num_of_equip;
        int* constant;
    public:
        character();
        character(std::string, const stats&, int, level, role[], int, int[]);
        ability get_ability(int, int);
        int get_num_of_roles();
        int get_num_of_equip();
        std::string get_name();
        stats get_stat_global();
        level get_level();
        role get_roles(int);
        weapon get_weapon(int);
        weapon& get_wep_f();
        costume get_costume(int);
        void get_state_turn(ability&);
        void set_turn_state_minus();
        void rest_mp(int, int);

        void rest_all();

        char get_fisical_magical(int, int);

        void set_stats_for_weapon(std::string[], int);
        void redebuff();

        void show_act_stats();

        void equip_weapon(int, weapon&);
        void unequip_weapon(int);
        void equip_costume(int, costume&);
        void unequip_costume(int);

        void modify_stats_equip_or_level();
        //void modify_stats_buff_debuff();
        void set_experience_entity(float);
        void set_experience_class(float);

        void take_damage(int, ability&);

        void damage(int, ability&);
        void buff_debuff();

        void show_equipment();

        void change_class(int, int);
        void show_stats();
        void show_stats_in_combat();
        void show_for_elect();
        ~character();
        friend class Combat;
        friend class consumible;
    };

    class enemy
    {
        std::string name;
        //std::string state;
        //state** _state;
        std::string element;
        std::string code_state;
        int turn_state;
        float experience;
        float experience_class;
        stats stadistic;
        stats act_statdistic;
        ability* abilities;
        int num_ability;
    public:
        enemy();
        enemy(const enemy&);
        enemy(std::string, float, float, stats&, ability[], int, table_element&, int);
        void buff_debuff();
        float get_experience();
        float get_experience_class();
        void get_state_turn(ability&);
        void turn_state_minus();
        void rest_mp(int);
        void set_name(std::string);

        std::string get_name();

        char get_fisical_magical(int);
        void redebuff_();

        bool benefic_ability_election(int);

        void take_damage(int, ability&, table_element&, weapon&);
        ability& get_ability(int);
        void show_stats();
        void show_in_combat();
        ~enemy();
        friend class Combat;
        friend class stats;
        friend class consumible;
    };







    // para que te guies enemy[i].act_statdistic.get_stat_value(0) es la vida actual del enemigo
    // y player[i].act_stats.get_stat_value(o) es la vida actual del personaje

    table_element::table_element(std::string array_elements[], int sizes)
    {
        element_list = new std::string[sizes];
        _size = sizes;
        array_weakness = new int* [_size];
        for (int i = 0; i < _size; i++)
            element_list[i] = array_elements[i];
        for (int i = 0; i < sizes; i++)
            array_weakness[i] = new int[_size];
        for (int i = 0; i < _size; i++)
            for (int j = 0; j < _size; j++)
                array_weakness[i][j] = 1;
    }
    void table_element::set_debilities(std::string strong, std::string weak, std::string str)
    {
        bool x = false, y = false, z = false;
        int s, t, u;
        for (int i = 0; i < _size; i++) {
            if (element_list[i] == strong) {
                s = i;
                x = true;
            }
            if (element_list[i] == weak) {

                t = i;
                y = true;
            }
            if (element_list[i] == str) {

                u = i;
                z = true;
            }
        }
        if (x == true && y == true && z == true) {
            if (t != u) {
                array_weakness[s][t] = 2;
                array_weakness[t][s] = 0;
                array_weakness[u][s] = 2;
            }
            else
            {
                array_weakness[s][t] = 3;
                array_weakness[t][s] = 3;
                array_weakness[u][s] = 3;
            }
        }

    }
    std::string table_element::get_element(int x)
    {
        return element_list[x];
    }
    void table_element::show_table()
    {
        for (int i = 0; i < _size; i++)
            std::cout << element_list[i] << " ";
        std::cout << "\n";
        for (int i = 0; i < _size; i++) {
            for (int j = 0; j < _size; j++)
                std::cout << array_weakness[i][j] << " ";
            std::cout << "\n";
        }
    }
    int table_element::_s_w_n(std::string elem1, std::string elem2)
    {
        for (int i = 0; i < _size; i++)
            for (int j = 0; j < _size; j++)
                if (element_list[i] == elem1 && element_list[j] == elem2)
                    return array_weakness[i][j];
        return 1;
    }
    table_element::~table_element()
    {
        delete[] element_list;
        for (int i = 0; i < _size; i++)
            delete[] array_weakness[i];
        delete[] array_weakness;
    }

    stats::stats()
    {
        _size = 0;
        this->stadistic_name = nullptr;
        this->value = nullptr;
        this->_state = nullptr;
    }

    stats::stats(std::string _list[], int _list_value[], int _siz)
    {
        _size = _siz;
        this->stadistic_name = new std::string[_size];
        this->value = new int[_size];
        for (int i = 0; i < _size; i++)
        {
            this->stadistic_name[i] = _list[i];
            this->value[i] = _list_value[i];
        }
        this->_state = new state[_size];
        for (int i = 0; i < _size; i++)
            _state[i] = state();
    }

    stats::stats(const stats& o)
    {
        _size = o._size;
        this->stadistic_name = new std::string[_size];
        this->value = new int[_size];
        for (int i = 0; i < _size; i++)
        {
            stadistic_name[i] = o.stadistic_name[i];
            value[i] = o.value[i];
        }
        this->_state = new state[_size];
        for (int i = 0; i < _size; i++)
            _state[i] = state();
    }

    void stats::set_v_value(int pos, int new_value)
    {
        value[pos] = new_value;
    }

    std::string stats::get_stat_name(int x)
    {
        return stadistic_name[x];
    }
    int stats::get_stat_value(int x)
    {
        return value[x];
    }
    int stats::get_size()
    {
        return _size;
    }
    void stats::set_name(std::string _list[])
    {
        for (int i = 0; i < _size; i++)
            stadistic_name[i] = _list[i];
    }
    void stats::set_value(int _list[])
    {
        for (int i = 0; i < _size; i++)
            value[i] = _list[i];
    }
    void stats::sum_value(int pos, int sum)
    {
        value[pos] += sum;
    }
    void stats::show_data()
    {
        for (int i = 0; i < _size; i++)
            std::cout << "Stat  name: " << stadistic_name[i] << " value: " << value[i] << "\n";
    }
    void stats::set_state(std::string name, int stat_effect, int power, int turn)
    {
        for (int i = 0; i < _size; i++)
            if (_state[i].name == "normal") {
                _state[i].set_state(name, stat_effect, power, turn);
                break;
            }
    }
    void stats::pass_turn()
    {
        for (int i = 0; i < _size; i++)
            _state[i].set_turn();
    }
    void stats::remove_state(std::string nam)
    {
        for (int i = 0; i < _size; i++)
            if (_state[i].name == nam) {
                std::cout << "recovered for " << _state[i].name << "\n";
                _state[i].set_state("normal", 0, 0, 0);
                return;
            }
        std::cout << "no effect\n";
    }
    void stats::show_state()
    {
        for (int i = 0; i < _size; i++)
            if (_state[i].name != "normal")
                std::cout << _state[i].name << " " << _state[i].turn << "\n\n";
    }
    stats::~stats()
    {
        delete[]stadistic_name;
        delete[]value;
    }

    level::level()
    {
        act_level = 1;
        experience = 0;
        necesary_exp = 10;
        total_exp = 0;
        max_level = 100;
        constant = 2.781;
    }
    level::level(int x, float y, float z, float j, int w, float i)
    {
        act_level = x;
        experience = y;
        necesary_exp = z;
        total_exp = j;
        max_level = w;
        constant = i;
    }
    level::level(level& o)
    {
        act_level = o.get_level();
        experience = o.get_experience();
        necesary_exp = o.get_necesary_experience();
        total_exp = o.get_total_exp();
        max_level = o.get_max_level();
        constant = o.get_constant();
    }
    float level::get_total_exp()
    {
        return total_exp;
    }
    int level::get_level()
    {
        return act_level;
    }
    float level::get_experience()
    {
        return experience;
    }
    float level::get_necesary_experience()
    {
        return necesary_exp;
    }
    int level::get_max_level()
    {
        return max_level;
    }
    float level::get_constant()
    {
        return constant;
    }
    void level::set_necesary_experience()
    {
        necesary_exp = pow(get_constant(), act_level / 10) * 100;
    }
    void level::add_exp(float x)
    {
        std::cout << "you got " << x << " experience points\n";
        experience += x;
        total_exp += x;
        validation_system();
    }
    void level::level_up(float f)
    {
        experience = f;
        if (act_level < max_level) {
            act_level++;
            std::cout << "you got level " << act_level << "\n";
        }
        set_necesary_experience();
        validation_system();
    }
    void level::validation_system()
    {
        if (experience >= necesary_exp) {
            float f = experience - necesary_exp;
            level_up(f);
        }
    }

    ability::ability() : _state()
    {
        name = "empty";
        //state = "000000";
        power = 0;
        element = "empty";
        state_name = "empty";
        consume = 0;
    }

    ability::ability(ability& o) : _state()
    {
        name = o.get_name();
        //state = o.get_state();
        power = o.get_power();
        element = o.get_element();
        state_name = o.get_state_name();
        consume = o.get_consume();
        _state.set_state(o._state.name, o._state.stat_affect, o._state.power, o._state.turn);
    }

    ability::ability(std::string _name, int _power, table_element& _table, int pos, std::string name_state, int cons, std::string n, int s, int p, int t, bool fm) : _state()
    {
        name = _name;
        // state = _state;
        power = _power;
        element = _table.get_element(pos);
        state_name = name_state;
        consume = cons;
        phisical_magical = fm;
        this->_state.set_state(n, s, p, t);
    }
    std::string ability::get_name()
    {
        return name;
    }
    void ability::modify_abilities(ability& o)
    {
        name = o.get_name();
        //state = o.get_state();
        power = o.get_power();
        element = o.get_element();
        state_name = o.get_state_name();
        consume = o.get_consume();
        _state.set_state(o._state.name, o._state.stat_affect, o._state.power, o._state.turn);

    }
    std::string ability::get_element()
    {
        return element;
    }
    int ability::get_power()
    {
        return power;
    }
    int ability::get_consume()
    {
        return consume;
    }
    bool ability::get_phisical_magical()
    {
        return phisical_magical;
    }
    std::string ability::get_state_name()
    {
        return state_name;
    }
    void ability::show_data()
    {
        std::cout << "Name: " << name << "\n";
        //std::cout << "State: " << state_name << " code effect: " << state << "\n";
        std::cout << "Power: " << power << "\n";
        std::cout << "Element: " << element << "\n";
        std::cout << "consume: " << consume << "\n";
        _state.show_data();
    }

    item::item()
    {
        name = "empty";
        description = "empty";
    }
    item::item(std::string _name, std::string _description)
    {
        name = _name;
        description = _description;
    }
    std::string item::get_name()
    {
        return name;
    }
    std::string item::get_description()
    {
        return description;
    }
    void item::show_data()
    {
        std::cout << "\n\nname: " << name << "\n";
        std::cout << "description: " << description << "\n";
    }
    /*
    weapon::weapon() : item()
    {
        element = "empty";
        weapon_type = "empty";
        buff_debuff = new int[7];
        for (int i = 0; i < _size; i++)
            buff_debuff[i] = 0;
        _size = 7;
    }
    weapon::weapon(std::string _name, std::string _description, std::string _weapon_type, table_element& _table, int pos, int _buff_debuff[], int siz) : item(_name, _description)
    {
        weapon_type = _weapon_type;
        element = _table.get_element(pos);
        buff_debuff = new int[siz];
        _size = siz;
        for (int i = 0; i < _size; i++)
            buff_debuff[i] = _buff_debuff[i];
    }
    weapon::weapon(weapon& o)
    {
        name = o.get_name();
        description = o.get_description();
        weapon_type = o.get_weapon_type();
        element = o.get_element();
        _size = o.get_size();
        buff_debuff = new int[_size];
        for (int i = 0; i < _size; i++)
            buff_debuff[i] = o.get_buff_debuff(i);
    }
    void weapon::modify(weapon& o)
    {
        name = o.name;
        description = o.description;
        weapon_type = o.weapon_type;
        element = o.element;
        _size = o._size;
        for (int i = 0; i < _size; i++)
            buff_debuff[i] = o.buff_debuff[i];
    }
    void weapon::modify_unequip()
    {
        element = "empty";
        weapon_type = "empty";
        for (int i = 0; i < _size; i++)
            buff_debuff[i] = 0;
    }
    std::string weapon::get_name()
    {
        return  item::get_name();
    }
    std::string weapon::get_decription()
    {
        return item::get_description();
    }
    std::string weapon::get_element()
    {
        return element;
    }
    std::string weapon::get_weapon_type()
    {
        return weapon_type;
    }
    int weapon::get_buff_debuff(int pos)
    {
        return buff_debuff[pos];
    }
    int weapon::get_size()
    {
        return _size;
    }
    void weapon::show_data()
    {
        item::show_data();
        std::cout << "weapon type : " << weapon_type << "\n";
        std::cout << "element : " << element << "\n";
        for (int i = 0; i < _size; i++)
            std::cout << " " << buff_debuff[i];
        std::cout << "\n\n";
    }

    weapon::~weapon()
    {
        delete[]buff_debuff;
    }
    */
    role::role()
    {
        _size = 0;
        name = "empty";
        code_stats = "empty";
        code_weapons = "empty";
        hab = nullptr;
        level_to_use = nullptr;
        level_of_role = level();
    }

    role::role(std::string _name, std::string _code_stats, std::string _code_weapon, ability abilities[], level lvl, int to_use[], int _siz)
    {
        _size = _siz;
        name = _name;
        code_stats = _code_stats;
        code_weapons = _code_weapon;
        hab = new ability[_size];
        level_to_use = new int[_size];
        for (int i = 0; i < _size; i++)
        {
            hab[i] = abilities[i];
            level_to_use[i] = to_use[i];
        }
        level_of_role = lvl;
    }
    role::role(role& o)
    {
        name = o.get_name();
        _size = o.get_size();
        code_stats = o.get_code_stats();
        code_weapons = o.get_code_weapons();
        hab = new ability[_size];
        level_to_use = new int[_size];
        for (int i = 0; i < _size; i++)
        {
            hab[i] = ability(o.get_ability(i));
            level_to_use[i] = o.get_level_to_use(i);
        }
        level_of_role = o.get_lvl();
    }
    void role::copy(role& o)
    {
        name = o.get_name();
        _size = o.get_size();
        code_stats = o.get_code_stats();
        code_weapons = o.get_code_weapons();
        hab = new ability[_size];
        level_to_use = new int[_size];
        for (int i = 0; i < _size; i++)
        {
            hab[i] = ability(o.get_ability(i));
            level_to_use[i] = o.get_level_to_use(i);
        }
        level_of_role = o.get_lvl();
    }
    std::string role::get_name()
    {
        return name;
    }
    std::string role::get_code_stats()
    {
        return code_stats;
    }
    std::string role::get_code_weapons()
    {
        return code_weapons;
    }
    int role::get_level()
    {
        return (int)level_of_role.get_level();
    }
    int role::get_code_role(int pos)
    {
        char num = code_stats[pos];
        if (num == '\0')
            return 0;
        return num - '0';
    }
    void role::add_level(float exp)
    {
        level_of_role.add_exp(exp);
    }
    level role::get_lvl()
    {
        return level_of_role;
    }
    ability& role::get_ability(int pos)
    {
        return hab[pos];
    }
    int role::get_level_to_use(int pos)
    {
        return level_to_use[pos];
    }
    int role::get_size()
    {
        return _size;
    }
    void role::display_habs()
    {
        bool r = false;
        std::cout << "disponible abilities: \n\n";
        for (int i = 0; i < _size; i++)
            if (get_level() >= level_to_use[i]) {
                hab[i].show_data();
                std::cout << "level to use: " << level_to_use[i] << "\n";
                r = true;
            }
        if (!r)
            std::cout << "no abilities disponible with your level\n\n";
    }
    void role::show_data()
    {
        std::cout << "\n\nclass name: " << name << "\n";
        std::cout << "code for stats modification: " << code_stats << "\n";
        std::cout << "code for weapon efectivity: " << code_weapons << "\n\n";
        for (int i = 0; i < _size; i++)
        {
            hab[i].show_data();
            std::cout << "level to use: " << level_to_use[i] << "\n\n";
        }
        std::cout << "level for this role: " << level_of_role.get_level() << "\n\n";
    }
    role:: ~role()
    {
        delete[]hab;
        delete[]level_to_use;

    }
    character::character()
    {
        name = "empty";
        state = "normal";
        _stats = stats();
        act_stats = stats();
        code_state = "00000";
        size_of_roles = 0;
        _level = level();
        turn_state = 0;
        roles = nullptr;
        point_role = nullptr;
        weapons = nullptr;
        costumes = nullptr;
        constant = nullptr;
    }
    character::character(std::string _name, const stats& _sts, int num_of_roles, level _levl, role _list[], int equip, int con[]) :_stats(_sts), act_stats(_sts)
    {
        name = _name;
        state = "normal";
        size_of_roles = num_of_roles;
        _level = level(_levl);
        code_state = "00000";
        turn_state = 0;
        roles = new role[size_of_roles];
        point_role = new int[2];
        num_of_equip = equip;
        weapons = new weapon*[2];
        costumes = new costume * [4];

        for (int i = 0; i < 2; i++)
            weapons[i] = new weapon;
        for (int i = 0; i < 4; i++)
            costumes[i] = new costume;
        //equipment = new weapon[num_of_equip];
        for (int i = 0; i < size_of_roles; i++)
        {
            roles[i] = _list[i];
        }
        /*constant = new int[_stats.get_size()];
        for (int i = 0; i < _stats.get_size(); i++) {
            constant[i] = con[i];
        }*/

        int tam = _stats.get_size();
        constant = new int[tam];
        for (int i = 0; i < tam; i++)
            constant[i] = con[i];

        _stats.set_value(con);
        act_stats.set_value(con);
        _stats.show_data();
        point_role[0] = 0;
        point_role[1] = 1;
        modify_stats_equip_or_level();
    }
    ability character::get_ability(int pos_role, int pos)
    {
        return roles[pos_role].get_ability(pos);
    }
    std::string character::get_name()
    {
        return name;
    }
    int character::get_num_of_roles()
    {
        return size_of_roles;
    }
    int character::get_num_of_equip()
    {
        return num_of_equip;
    }
    level character::get_level()
    {
        return _level;
    }
    void character::set_turn_state_minus()
    {
        act_stats.pass_turn();
    }
    stats character::get_stat_global()
    {
        return _stats;
    }
    role character::get_roles(int pos)
    {
        return roles[pos];
    }
    weapon character::get_weapon(int pos)
    {
        return *weapons[pos];
    }
    costume character::get_costume(int pos)
    {
        return *costumes[pos];
    }
    char character::get_fisical_magical(int pos, int role)
    {
        int i = 0;
        return roles[point_role[role]].get_ability(pos).get_phisical_magical();
    }
    weapon& character::get_wep_f()
    {
        return *weapons[0];
    }
    void character::equip_weapon(int pos, weapon& new_weapon)
    {
        if (pos < 2 && pos >= 0)
            *weapons[pos]=new_weapon;
        character::modify_stats_equip_or_level();
    }
    void character::unequip_weapon(int pos)
    {
        if (pos < 2 && pos >= 0)
            *weapons[pos]=weapon();
        character::modify_stats_equip_or_level();
    }
    void character::equip_costume(int pos, costume& new_costume)
    {
        if (pos < 4 && pos >= 0)
            *costumes[pos] = new_costume;
        character::modify_stats_equip_or_level();
    }
    void character::unequip_costume(int pos)
    {
        if (pos < 4 && pos >= 0)
            *costumes[pos] = costume();
        character::modify_stats_equip_or_level();
    }
    /*
    void character::modify_stats_buff_debuff()
    {
        if (turn_state > 0) {

            int i = 0;
            while (code_state[i] != '\0')
                i++;
            int turn_p = (code_state[i - 3] - '0') + (code_state[i - 4] - '0') * 10;
            i = 0;
            int counter = 0;
            while (code_state[i] != ' ')
            {
                if (code_state[i] <= '9' && code_state[i] >= '0') {

                    if (counter != 0 && counter != 1 && turn_p == turn_state) {
                        act_stats.sum_value(counter, (_stats.get_stat_value(counter) * (code_state[i] - '0')) / 10);
                        std::cout << name << "'s " << _stats.get_stat_name(counter) << "  increased in " << (_stats.get_stat_value(counter) * (code_state[i] - '0')) / 10 << " by " << state;
                    }
                    else if (counter == 0 || counter == 1) {
                        act_stats.sum_value(counter, (_stats.get_stat_value(counter) * (code_state[i] - '0')) / 10);
                        std::cout << name << "'s " << _stats.get_stat_name(counter) << "increased in " << (_stats.get_stat_value(counter) * (code_state[i] - '0')) / 10 << " by " << state;
                    }
                    if (act_stats.get_stat_name(counter) == "life points" && (act_stats.get_stat_value(counter) > _stats.get_stat_value(counter)))
                        act_stats.set_v_value(counter, _stats.get_stat_value(0));
                    if (act_stats.get_stat_name(counter) == "magic points" && (act_stats.get_stat_value(counter) > _stats.get_stat_value(counter)))
                        act_stats.set_v_value(counter, _stats.get_stat_value(1));

                }
                counter++;
                i++;
            }
            i++;
            counter = 0;
            while (code_state[i] != ' ')
            {
                if (code_state[i] <= '9' && code_state[i] >= '0') {

                    if (counter != 0 && counter != 1 && turn_p == turn_state) {
                        act_stats.sum_value(counter, -(_stats.get_stat_value(counter) * (code_state[i] - '0')) / 10);
                        std::cout << name << "'s " << _stats.get_stat_name(counter) << "decreased in " << (_stats.get_stat_value(counter) * (code_state[i] - '0')) / 10 << " by " << state;
                    }
                    else if (counter == 0 || counter == 1) {
                        act_stats.sum_value(counter, -(_stats.get_stat_value(counter) * (code_state[i] - '0')) / 10);
                        std::cout << name << "'s " << _stats.get_stat_name(counter) << "decreased in " << (_stats.get_stat_value(counter) * (code_state[i] - '0')) / 10 << " by " << state;
                    }
                    if (act_stats.get_stat_name(counter) == "life points" && (act_stats.get_stat_value(counter) < 0))
                        act_stats.set_v_value(counter, 0);
                    if (act_stats.get_stat_name(counter) == "magic points" && (act_stats.get_stat_value(counter) < 0))
                        act_stats.set_v_value(counter, 0);

                }
                counter++;
                i++;
            }
        }

    }*/
    void character::buff_debuff()
    {
        for (int i = 0; i < _stats.get_size(); i++)
        {
            if (act_stats._state[i].name != "normal")
                if (turn_state == act_stats._state[i].turn && (act_stats._state[i].stat_affect != 1 && act_stats._state[i].stat_affect != 0)) {
                    std::cout << name << " take " << act_stats._state[i].power << " points, of " << act_stats.get_stat_name(act_stats._state[i].stat_affect) << " for " << act_stats._state[i].name;
                    act_stats.set_v_value(act_stats._state[i].stat_affect,_stats.get_stat_value(act_stats._state[i].stat_affect)+ act_stats._state[i].power);
                }
                else if (act_stats._state[i].stat_affect == 1 || act_stats._state[i].stat_affect == 0) {
                    std::cout << name << " take " << act_stats._state[i].power << " points, of " << act_stats.get_stat_name(act_stats._state[i].stat_affect) << " for " << act_stats._state[i].name;
                    act_stats.set_v_value(act_stats._state[i].stat_affect, _stats.get_stat_value(act_stats._state[i].stat_affect) + act_stats._state[i].power);
                }
            if (act_stats.get_stat_value(0) < 0)
                act_stats.set_v_value(0, 0);
            if (act_stats.get_stat_value(1) < 0)
                act_stats.set_v_value(1, 0);
            if (act_stats.get_stat_value(0) > _stats.get_stat_value(0))
                act_stats.set_v_value(0, _stats.get_stat_value(0));
            if (act_stats.get_stat_value(1) > _stats.get_stat_value(1))
                act_stats.set_v_value(1, _stats.get_stat_value(1));
            if (act_stats._state[i].turn == 1)
            {
                std::cout << name << " recovered from " << act_stats._state[i].name;
                if (act_stats._state[i].stat_affect != 1 && act_stats._state[i].stat_affect != 0)
                    act_stats.set_v_value(act_stats._state[i].stat_affect, _stats.get_stat_value(act_stats._state[i].stat_affect));
            }
        }
    }
    
    /*
    void character::get_state_turn(ability& o)
    {
        int i = 0;
        while (o.get_state()[i] != '\0')
            i++;
        code_state = o.get_state();
        state = o.get_state_name();
        std::cout << (o.get_state()[i - 3] - '0') + (o.get_state()[i - 4] - '0') * 10;
        turn_state = (o.get_state()[i - 3] - '0') + (o.get_state()[i - 4] - '0') * 10;
    }*/
    void character::get_state_turn(ability& o)
    {
        act_stats.set_state(o._state.name, o._state.stat_affect, o._state.power, o._state.turn);
    }


    /*
        |0000000 0000000 00 m|
    */
    void character::modify_stats_equip_or_level()
    {

        for (int i = 0; i < _stats.get_size(); i++) {
            _stats.set_v_value(i, constant[i] + (roles[point_role[0]].get_code_role(i) * _level.get_level()));
        }
        for (int i = 0; i < 2; i++)
            if (weapons[i]->get_name() != "empty") {
                for (int j = 0; j < weapons[i]->get_num(); j++) {
                    for(int k = 0; k < _stats.get_size();k++)
                        if(weapons[i]->names[j]==_stats.get_stat_name(k))
                            _stats.sum_value(k, weapons[i]->improve[j]);
                }
            }
        for (int i = 0; i < 4; i++)
            if (costumes[i]->get_name() != "empty") {
                for (int j = 0; j < costumes[i]->get_num(); j++) {
                    for (int k = 0; k < _stats.get_size(); k++)
                        if (costumes[i]->names[j] == _stats.get_stat_name(k))
                            _stats.sum_value(k, costumes[i]->improve[j]);
                }
            }
        for (int i = 0; i < _stats.get_size(); i++)
            if (i != 0 && i != 1)
                act_stats.set_v_value(i, _stats.get_stat_value(i));

    }
    void character::rest_mp(int pos, int role)
    {
        act_stats.set_v_value(1, act_stats.get_stat_value(1) - roles[point_role[role]].get_ability(pos).get_consume());
        if (act_stats.get_stat_value(1) < 0)
            act_stats.set_v_value(1, 0);

    }
    void character::set_experience_class(float experience)
    {
        roles[point_role[0]].add_level(experience);
        character::modify_stats_equip_or_level();
    }
    void character::set_experience_entity(float experience)
    {
        _level.add_exp(experience);
        character::modify_stats_equip_or_level();
    }
    void character::change_class(int pr_role, int sec_role)
    {
        point_role[0] = pr_role;
        point_role[1] = sec_role;
        character::modify_stats_equip_or_level();
    }
    void character::show_stats()
    {
        std::cout << "name: " << name << "\n";
        std::cout << "principal role: " << roles[point_role[0]].get_name() << " level of role: " << roles[point_role[0]].get_level() << "\n";
        std::cout << "second role: " << roles[point_role[1]].get_name() << " level of role: " << roles[point_role[1]].get_level() << "\n";
        std::cout << "level: " << _level.get_level() << "\n\n";
        _stats.show_data();
        roles[point_role[0]].show_data();
        roles[point_role[1]].show_data();

    }
    void character::show_stats_in_combat()
    {
        std::cout << name << "\n" << act_stats.get_stat_value(0) << "/" << _stats.get_stat_value(0) << "\n" << act_stats.get_stat_value(1) << "/" << _stats.get_stat_value(1);
        std::cout << "\n" << state;
    }

    void character::show_for_elect()
    {
        act_stats.show_data();
    }
    void character::rest_all()
    {
        for (int i = 0; i < _stats.get_size(); i++)
            act_stats.set_v_value(i, _stats.get_stat_value(i));
    }// << "\n";
    void character::take_damage(int power, ability& o)
    {
        int con = rand() % 100 + 85;
        if (o.get_name() != "empty") {
            int pow = o.get_power();
            int i = 0;
         
            bool mn = o.get_phisical_magical();
            if (mn == true) {
                act_stats.sum_value(0, -((power + con) / act_stats.get_stat_value(3) * (o.get_power() / 10)));
                std::cout << name << " received " << o.get_name();
                if (-((power + con) / act_stats.get_stat_value(3) * (o.get_power() / 10)) != 0)
                    std::cout << " and took " << ((power + con) / act_stats.get_stat_value(3) * (o.get_power() / 10)) << " damage " << "\n";
            }
            if (mn == false) {
                act_stats.sum_value(0, -((power + con) / act_stats.get_stat_value(5) * (o.get_power() / 10)));
                std::cout << name << " received " << o.get_name();
                if (-((power + con) / act_stats.get_stat_value(5) * (o.get_power() / 10)) != 0)
                    std::cout << " and took " << ((power + con) / act_stats.get_stat_value(5) * (o.get_power() / 10)) << " damage " << "\n";
            }
            if (o.get_state_name() != "normal")
                get_state_turn(o);
        }
        else
        {
            if (o.get_state_name() != "empty") {
                act_stats.sum_value(0, -((power + con) / act_stats.get_stat_value(3) * (o.get_power() / 10)));
                std::cout << name << " received " << o.get_name();
                if (-((power + con) / act_stats.get_stat_value(3) * (o.get_power() / 10)) != 0)
                    std::cout << " and took " << ((power + con) / act_stats.get_stat_value(3) * (o.get_power() / 10)) << " damage " << "\n";
            }
            else {
                act_stats.sum_value(0, -((power + con) / act_stats.get_stat_value(3)));
                std::cout << name << " took " << ((power + con) / act_stats.get_stat_value(3) * (o.get_power() / 10)) << " damage " << "\n";
            }
        }
        if (act_stats.get_stat_value(0) < 0)
            act_stats.set_v_value(0, 0);

    }


    void character::damage(int power, ability& o)
    {
        int con = rand() % 100 + 85;
        if (o.get_name() != "empty") {
            int pow = o.get_power();
            int i = 0;
           
            bool mn = o.get_phisical_magical();
            if (mn == true) {
                act_stats.sum_value(0, -((power + con) / act_stats.get_stat_value(3) * (o.get_power() / 10)));
                std::cout << name << " received " << o.get_name();
                if (-((power + con) / act_stats.get_stat_value(3) * (o.get_power() / 10)) != 0)
                    std::cout << " and took " << ((power + con) / act_stats.get_stat_value(3) * (o.get_power() / 10)) << " damage " << "\n";
            }
            if (mn == true) {
                act_stats.sum_value(0, -((power + con) / act_stats.get_stat_value(5) * (o.get_power() / 10)));
                std::cout << name << " received " << o.get_name();
                if (-((power + con) / act_stats.get_stat_value(5) * (o.get_power() / 10)) != 0)
                    std::cout << " and took " << ((power + con) / act_stats.get_stat_value(5) * (o.get_power() / 10)) << " damage " << "\n";
            }
            if (o._state.name != "normal")
                get_state_turn(o);
        }
        else
        {
            if (o.get_state_name() != "empty") {
                act_stats.sum_value(0, -((power + con) / act_stats.get_stat_value(3) * (o.get_power() / 10)));
                std::cout << name << " received " << o.get_name();
                if (-((power + con) / act_stats.get_stat_value(3) * (o.get_power() / 10)) != 0)
                    std::cout << " and took " << ((power + con) / act_stats.get_stat_value(3) * (o.get_power() / 10)) << " damage " << "\n";
            }
            else {
                act_stats.sum_value(0, -((power + con) / act_stats.get_stat_value(3)));
                std::cout << name << " took " << ((power + con) / act_stats.get_stat_value(3) * (o.get_power() / 10)) << " damage " << "\n";
            }
        }
        if (act_stats.get_stat_value(0) < 0)
            act_stats.set_v_value(0, 0);

    }
    


    void character::redebuff()
    {
        for (int i = 0; i < _stats.get_size(); i++)
            if (i != 0 && i != 1)
                act_stats.set_v_value(i, _stats.get_stat_value(i));
    }
    void character::show_equipment()
    {
        for (int i = 0; i < 2; i++)
            weapons[i]->show_data();
    }
    void character::show_act_stats()
    {
        act_stats.show_data();
    }
    void character::set_stats_for_weapon(std::string l_weapon[], int num)
    {
        int sum = 0;
        for (int i = 0; i < num; i++)
            for (int j = 0; j < 2; j++)
                if (l_weapon[num] == weapons[j]->get_type())
                {
                    if (roles[point_role[0]].get_code_weapons()[i] == 's')
                        sum += _stats.get_stat_value(2);
                    if (roles[point_role[0]].get_code_weapons()[i] == 'a')
                        sum += ((_stats.get_stat_value(2) / 4) * 3);
                    if (roles[point_role[0]].get_code_weapons()[i] == 'b')
                        sum += ((_stats.get_stat_value(2) / 3) * 2);
                    if (roles[point_role[0]].get_code_weapons()[i] == 'c')
                        sum += ((_stats.get_stat_value(2) / 2));
                    if (roles[point_role[0]].get_code_weapons()[i] == 'd')
                        sum += ((_stats.get_stat_value(2) / 4));
                }
        act_stats.set_v_value(2, sum);
    }

    character::~character()
    {
        delete[]point_role;
        delete[]weapons;
        delete[]costumes;
        delete[]constant;
    }

    enemy::enemy() : stadistic(), act_statdistic(), abilities()
    {
        element = "empty";
        name = "empty";
        code_state = "00000";
        experience = 0;
        experience_class = 0;
        num_ability = 0;
        turn_state = 0;
    }
    enemy::enemy(const enemy& o) : stadistic(o.stadistic), act_statdistic(o.stadistic)
    {
        name = o.name;
        experience = o.experience;
        experience_class = o.experience_class;
        num_ability = o.num_ability;
        turn_state = 0;
        code_state = "00000";
        element = o.element;
        abilities = new ability[num_ability];
        for (int i = 0; i < num_ability; i++)
            abilities[i].modify_abilities(o.abilities[i]);
    }
    enemy::enemy(std::string _name, float exp, float exp_class, stats& _sts, ability habs[], int num_ab, table_element& table, int pos) : stadistic(_sts), act_statdistic(_sts)
    {
        name = _name;
        experience = exp;
        experience_class = exp_class;
        num_ability = num_ab;
        turn_state = 0;
        code_state = "00000";
        element = table.get_element(pos);
        abilities = new ability[num_ability];
        for (int i = 0; i < num_ability; i++)
            abilities[i].modify_abilities(habs[i]);
    }
    /*
    void enemy::buff_debuff()
    {
        if (turn_state > 0) {
            std::string eval = code_state;
            int i = 0;
            while (eval[i] != '\0')
                i++;
            int turn_p = eval[i - 3] - '0' + (eval[i - 4] - '0' * 10);
            i = 0;
            int counter = 0;
            while (eval[i] != ' ')
            {
                if (eval[i] <= '9' && eval[i] >= '0') {

                    if (counter != 0 && counter != 1 && turn_p == turn_state) {
                        act_statdistic.sum_value(counter, (stadistic.get_stat_value(counter) * (code_state[i] - '0')) / 10);
                        std::cout << name << "'s " << stadistic.get_stat_name(counter) << "increased in " << (stadistic.get_stat_value(counter) * (code_state[i] - '0')) / 10 << " by " << state << "\n";
                    }
                    else if (counter == 0 || counter == 1) {
                        act_statdistic.sum_value(counter, (stadistic.get_stat_value(counter) * (code_state[i] - '0')) / 10);
                        std::cout << name << "'s " << stadistic.get_stat_name(counter) << "increased in " << (stadistic.get_stat_value(counter) * (code_state[i] - '0')) / 10 << " by " << state << "\n";
                    }
                    if (act_statdistic.get_stat_name(counter) == "life points" && (act_statdistic.get_stat_value(counter) > stadistic.get_stat_value(counter)))
                        act_statdistic.set_v_value(counter, stadistic.get_stat_value(counter));
                    if (act_statdistic.get_stat_name(counter) == "magic points" && (act_statdistic.get_stat_value(counter) > stadistic.get_stat_value(counter)))
                        act_statdistic.set_v_value(counter, stadistic.get_stat_value(counter));

                }
                counter++;
                i++;
            }
            i++;
            counter = 0;
            while (eval[i] != ' ')
            {
                if (eval[i] <= '9' && eval[i] >= '0') {

                    if (counter != 0 && counter != 1 && turn_p == turn_state) {
                        act_statdistic.sum_value(counter, -(stadistic.get_stat_value(counter) * (code_state[i] - '0')) / 10);
                        std::cout << name << "'s " << stadistic.get_stat_name(counter) << "decreased in " << (stadistic.get_stat_value(counter) * (code_state[i] - '0')) / 10 << " by " << state << "\n";
                    }
                    else if (counter == 0 || counter == 1) {
                        act_statdistic.sum_value(counter, -(stadistic.get_stat_value(counter) * (code_state[i] - '0')) / 10);
                        std::cout << name << "'s " << stadistic.get_stat_name(counter) << "decreased in " << (stadistic.get_stat_value(counter) * (code_state[i] - '0')) / 10 << " by " << state << "\n";
                    }
                    //std::cout << -(stadistic.get_stat_value(counter) * (code_state[i] - '0')) / 10;
                    if (act_statdistic.get_stat_name(counter) == "life points" && (act_statdistic.get_stat_value(counter) < 0))
                        act_statdistic.set_v_value(counter, 0);
                    if (act_statdistic.get_stat_name(counter) == "magic points" && (act_statdistic.get_stat_value(counter) < 0))
                        act_statdistic.set_v_value(counter, 0);

                }
                counter++;
                i++;
            }
        }

    }
    */

    void enemy::buff_debuff()
    {
        for (int i = 0; i < stadistic.get_size(); i++)
        {
            if (act_statdistic._state[i].name != "normal")
                if (turn_state == act_statdistic._state[i].turn && (act_statdistic._state[i].stat_affect != 1 && act_statdistic._state[i].stat_affect != 0)) {
                    std::cout << name << " take " << act_statdistic._state[i].power << " points of " << act_statdistic.get_stat_name(act_statdistic._state[i].stat_affect) << " for " << act_statdistic._state[i].name;
                    act_statdistic.set_v_value(act_statdistic._state[i].stat_affect, act_statdistic.get_stat_value(act_statdistic._state[i].stat_affect) + act_statdistic._state[i].power);
                }
                else if (act_statdistic._state[i].stat_affect == 1 || act_statdistic._state[i].stat_affect == 0) {
                    std::cout << name << " take " << act_statdistic._state[i].power << " points of " << act_statdistic.get_stat_name(act_statdistic._state[i].stat_affect) << " for " << act_statdistic._state[i].name;
                    act_statdistic.set_v_value(act_statdistic._state[i].stat_affect, act_statdistic.get_stat_value(act_statdistic._state[i].stat_affect) + act_statdistic._state[i].power);
                }
            if (act_statdistic.get_stat_value(0) < 0)
                act_statdistic.set_v_value(0, 0);
            if (act_statdistic.get_stat_value(1) < 0)
                act_statdistic.set_v_value(1, 0);
            if (act_statdistic.get_stat_value(0) > stadistic.get_stat_value(0))
                act_statdistic.set_v_value(0, stadistic.get_stat_value(0));
            if (act_statdistic.get_stat_value(1) > stadistic.get_stat_value(0))
                act_statdistic.set_v_value(1, stadistic.get_stat_value(0));
            if (act_statdistic._state[i].turn == 1)
            {
                std::cout << name << " recovered from " << act_statdistic._state[i].name;
                if (act_statdistic._state[i].stat_affect != 1 && act_statdistic._state[i].stat_affect != 0)
                    act_statdistic.set_v_value(act_statdistic._state[i].stat_affect, stadistic.get_stat_value(act_statdistic._state[i].stat_affect));
            }
        }
    }
    void enemy::get_state_turn(ability& o)
    {
        act_statdistic.set_state(o._state.name, o._state.stat_affect, o._state.power, o._state.turn);
    }
    void enemy::turn_state_minus()
    {
        act_statdistic.pass_turn();
    }
    char enemy::get_fisical_magical(int pos)
    {
        return abilities[pos].get_phisical_magical();
    }
    void enemy::rest_mp(int pos)
    {
        act_statdistic.set_v_value(1, abilities[pos].get_consume());
        if (act_statdistic.get_stat_value(1) < 0)
            act_statdistic.set_v_value(1, 0);
    }
    std::string enemy::get_name()
    {
        return name;
    }
    void enemy::take_damage(int power, ability& o, table_element& table, weapon& w)
    {
        int con = rand() % 100 + 10;
        if (o.get_name() != "empty") {
            int pow = o.get_power();
            float debi = table._s_w_n(element, o.get_element());
            if (debi == 0)
                debi = 0.5;
            if (debi == 3)
                debi = 2;
            float debw = table._s_w_n(element, w.get_element());
            if (debw == 0)
                debw = 0.5;
            if (debw == 3)
                debw = 2;
            int i = 0;
            
            bool mn = o.get_phisical_magical();
            if (mn == true) {
                std::cout << name << " it was sent to him " << o.get_name() << " and receive " << ((power + con) * debi * debw) / act_statdistic.get_stat_value(3) * o.get_power();
                act_statdistic.sum_value(0, -(((power + con) * debi * debw) / act_statdistic.get_stat_value(3) * o.get_power()));
            }
            if (mn == false) {
                std::cout << name << " it was sent to him " << o.get_name() << " and receive " << ((power + con) * debi * debw) / act_statdistic.get_stat_value(5) * o.get_power();
                act_statdistic.sum_value(0, -(((power + con) * debi) / act_statdistic.get_stat_value(5) * o.get_power()));
            }
            if (o.get_state_name() != "normal")
                get_state_turn(o);
        }
        else
        {
            float debi = table._s_w_n(element, w.get_element());
            if (debi == 0)
                debi = 0.5;
            if (debi == 3)
                debi = 2;
            act_statdistic.sum_value(0, -(((con)*debi) / act_statdistic.get_stat_value(3) * power / 10));
            std::cout << name << " receive " << ((power + con) * debi) / act_statdistic.get_stat_value(5) * o.get_power();

        }
        if (act_statdistic.get_stat_value(0) < 0)
            act_statdistic.set_v_value(0, 0);

    }
    ability& enemy::get_ability(int pos)
    {
        return abilities[pos];
    }
    void enemy::show_stats()
    {
        std::cout << "name :" << name << "\n";
        std::cout << "element: " << element << "\n";
        std::cout << "experience: " << experience << "\n";
        std::cout << "experience for class: " << experience_class << "\n";
        std::cout << "stats: \n\n";
        stadistic.show_data();
        for (int i = 0; i < num_ability; i++)
            abilities[i].show_data();
    }
    void enemy::show_in_combat()
    {
        std::cout << "name :" << name << "\n";
        std::cout << act_statdistic.get_stat_value(0) << "/" << stadistic.get_stat_value(0) << "\n";
        std::cout << act_statdistic.get_stat_value(1) << "/" << stadistic.get_stat_value(1) << "\n";

    }

    bool enemy::benefic_ability_election(int pos)
    {
        if (abilities[pos]._state.power > 0) 
                return true;
        return false;
    }
    void enemy::set_name(std::string new_name)
    {
        name = new_name;
    }
    void enemy::redebuff_()
    {
        for (int i = 0; i < stadistic.get_size(); i++)
            if (i != 0 && i != 1)
                act_statdistic.set_v_value(i, stadistic.get_stat_value(i));

    }
    float enemy::get_experience()
    {
        return experience;
    }
    float enemy::get_experience_class()
    {
        return experience_class;
    }
    enemy::~enemy()
    {
        delete[] abilities;
    }

    
    class consumible : public item {
        state stt;
        bool add_remove;
        std::string elem;
        int power;
    public:
        consumible(std::string, std::string, bool, std::string, int);
        consumible(std::string, std::string, std::string, int, int, int, bool, std::string, int);
        state& get_state();
        std::string get_element();
        bool getact();
        void show();
        void player_affect(character& o);
        void enemy_affect(enemy& o, table_element& i);
        friend class inventory;
    };

    consumible::consumible(std::string name, std::string description, bool ac, std::string elem, int power) : item(name, description), stt()
    {
        add_remove = ac;
        this->elem = elem;
        this->power = power;
    }
    consumible::consumible(std::string name, std::string description, std::string state_name, int staf, int pow, int turn, bool ac, std::string elem, int power) : item(name, description), stt()
    {
        add_remove = ac;
        this->elem = elem;
        this->power = power;
        stt.set_state(state_name, staf, turn, pow);
    }
    state& consumible::get_state()
    {
        return stt;
    }
    std::string consumible::get_element()
    {
        return elem;
    }
    bool consumible::getact()
    {
        return add_remove;
    }

    void consumible::show()
    {
        show_data();
        std::cout << "state : " << stt.name << "\n";
        if (add_remove == true)
            std::cout << "the state will add to the objetive \n";
        else
            std::cout << "the state will be remove to the objetive";
        std::cout << "\npower:" << power;
    }

    void consumible::player_affect(character& o)
    {
        ability aux;
        if (power > 0)
            o.take_damage(power, aux);
        if (add_remove == true)
        {
            std::cout << o.get_name() << " received " << name;
            if(stt.name != "normal")
                o.act_stats.set_state(stt.name, stt.stat_affect, stt.power, stt.turn);
        }
        else
        {
            std::cout << o.get_name() << " received " << name;
            if (stt.name != "normal")
                o.act_stats.remove_state(name);
        }
    }
    void consumible::enemy_affect(enemy& o, table_element& table)
    {
        ability aux;
        weapon we(0, nullptr, nullptr, elem, "0","0");

        if (power > 0)
            o.take_damage(power, aux, table, we);
        if (add_remove == true)
        {
            std::cout << o.get_name() << " received " << name;
            if (stt.name != "normal")
                o.act_statdistic.set_state(stt.name, stt.stat_affect, stt.power, stt.turn);
        }
        else
        {
            std::cout << o.get_name() << " received " << name;
            if (stt.name != "normal")
                o.act_statdistic.remove_state(name);
        }
    }

    struct inventory
    {
        consumible** consumibles;
        int num_con;
        weapon** weapons;
        int num_wea;
        costume** costumes;
        int num_equip;
   
        inventory();

        void push_consumible(std::string, std::string, std::string, int, int, int, bool, std::string, int);
        void push_weapon(int, std::string*, int*, std::string, std::string, int, int, int, std::string, std::string, std::string);
        void push_costume(int, std::string*, int*, std::string, std::string, int, int, int, std::string, std::string, std::string);

        void delete_consumible(int);
        void delete_weapon(int);
        void delete_costume(int);

        void use_item(int, character&);
        void use_item_enemy(int, enemy&, table_element& y);
        void equip_weapon(int, int, character&);
        void unequip_weapon(int, int, character&);
        void equip_costume(int, int, character&);
        void unequip_costume(int, int, character&);

        void show_con();
        void show_weap();
        void show_cost();

        ~inventory();
    };


    inventory::inventory()
    {
        consumibles = new consumible * [100];
        weapons = new weapon * [100];
        costumes = new costume * [100];
        num_con = 0;
        num_equip = 0;
        num_wea = 0;
    }

    void inventory::push_consumible(std::string name, std::string description, std::string stt_name, int statfect, int power, int turn, bool addremove, std::string elem, int powe)
    {
        if (num_con < 100) {
            consumibles[num_con] = new consumible(name, description, stt_name, statfect, power, turn, addremove, elem, powe);
            num_con++;
        }
    }

    void inventory::push_weapon(int num, std::string* stats, int* improvement, std::string element, std::string state_name, int stat_eff, int pow, int turns, std::string n, std::string d, std::string type)
    {
        if (num_wea < 100) {
            if (type == "sword") {
                weapons[num_wea] = new sword(num, stats, improvement, element, state_name, stat_eff, pow, turns, n, d);
                num_wea++;
                std::cout << "you got : " << weapons[num_wea - 1]->get_name() << "\n";
            }
            if (type == "shield") {
                weapons[num_wea] = new shield(num, stats, improvement, element, state_name, stat_eff, pow, turns, n, d);
                num_wea++;
                std::cout << "you got : " << weapons[num_wea - 1]->get_name() << "\n";
            }
            if (type == "spear") {
                weapons[num_wea] = new spear(num, stats, improvement, element, state_name, stat_eff, pow, turns, n, d);
                num_wea++;
                std::cout << "you got : " << weapons[num_wea - 1]->get_name() << "\n";
            }
            if (type == "axe") {
                weapons[num_wea] = new axe(num, stats, improvement, element, state_name, stat_eff, pow, turns, n, d);
                num_wea++;
                std::cout << "you got : " << weapons[num_wea - 1]->get_name() << "\n";
            }
            if (type == "knife") {
                weapons[num_wea] = new knife(num, stats, improvement, element, state_name, stat_eff, pow, turns, n, d);
                num_wea++;
                std::cout << "you got : " << weapons[num_wea - 1]->get_name() << "\n";
            }
            if (type == "bow") {
                weapons[num_wea] = new bow(num, stats, improvement, element, state_name, stat_eff, pow, turns, n, d);
                num_wea++;
                std::cout << "you got : " << weapons[num_wea - 1]->get_name() << "\n";
            }
            if (type == "crosier") {
                weapons[num_wea] = new crosier(num, stats, improvement, element, state_name, stat_eff, pow, turns, n, d);
                num_wea++;
                std::cout << "you got : " << weapons[num_wea - 1]->get_name() << "\n";
            }
        }
    }

    void inventory::push_costume(int num, std::string* stats, int* improvement, std::string element, std::string state_name, int stat_eff, int pow, int turns, std::string n, std::string d, std::string type)
    {
        if (num_equip < 100) {
            if (type == "head") {
                costumes[num_equip] = new head(num, stats, improvement, element, state_name, stat_eff, pow, turns, n, d);
                num_equip++;
                std::cout << "you got : " << costumes[num_equip - 1]->get_name() << "\n";
            }
            if (type == "armor") {
                costumes[num_equip] = new armor(num, stats, improvement, element, state_name, stat_eff, pow, turns, n, d);
                num_equip++;
                std::cout << "you got : " << costumes[num_equip - 1]->get_name() << "\n";
            }
            if (type == "legs") {
                costumes[num_equip] = new legs(num, stats, improvement, element, state_name, stat_eff, pow, turns, n, d);
                num_equip++;
                std::cout << "you got : " << costumes[num_equip - 1]->get_name() << "\n";
            }
            if (type == "accesory") {
                costumes[num_equip] = new accesory(num, stats, improvement, element, state_name, stat_eff, pow, turns, n, d);
                num_equip++;
                std::cout << "you got : " << costumes[num_equip - 1]->get_name() << "\n";
            }
        }
    }

    void inventory::delete_consumible(int pos)
    {
        if (pos < num_con) {
            
            for (int i = pos; i < num_con; i++)
                consumibles[i] = consumibles[i + 1];
            num_con--;
        }
    }

    void inventory::delete_weapon(int pos)
    {
        if (pos < num_equip) {
            if (weapons[pos]->get_equip() == false)
            {
                std::cout << weapons[pos]->get_name() << " deleted\n";
               
                for (int i = pos; i < num_wea; i++)
                    weapons[i] = weapons[i + 1];
                num_wea--;
            }
            else
                std::cout << "this weapon is equipped, cannot be delete this\n";
        }
    }

    void inventory::delete_costume(int pos)
    {
        if (pos < num_equip) {
            if (costumes[pos]->get_equip() == false)
            {
                std::cout << costumes[pos]->get_name() << " deleted\n";
               
                for (int i = pos; i < num_equip; i++)
                    costumes[i] = costumes[i + 1];
                num_equip--;
            }
            else
                std::cout << "this weapon is equipped, cannot be delete this\n";
        }
    }

    void inventory::equip_weapon(int po, int pos, character& o)
    {
        if (weapons[pos]->get_equip() == false)
        {
            o.equip_weapon(po, *weapons[pos]);
        }
    }
    void inventory::unequip_weapon(int po, int pos, character& o)
    {
        if (weapons[pos]->get_equip() == true) {
            if (o.get_weapon(po).get_name() == weapons[pos]->get_name()) {
                o.unequip_weapon(po);
                weapons[pos]->unequiped();
            }
        }
    }

    void inventory::equip_costume(int po, int pos, character& o)
    {
        if (costumes[pos]->get_equip() == false)
        {
            o.equip_costume(po, *costumes[pos]);
        }
    }
    void inventory::unequip_costume(int po, int pos, character& o)
    {
        if (costumes[pos]->get_equip() == true) {
            if (o.get_costume(po).get_name() == costumes[pos]->get_name()) {
                o.unequip_costume(po);
                costumes[pos]->unequiped();
            }
        }
    }

    void inventory::use_item(int pos, character& o)
    {
        consumibles[pos]->player_affect(o);
        delete_consumible(pos);
    }
    void inventory::use_item_enemy(int pos, enemy& o, table_element &y)
    {
        consumibles[pos]->enemy_affect(o, y);
        delete_consumible(pos);
    }

    void inventory::show_con()
    {
        for (int i = 0; i < num_con; i++)
            std::cout << "(" << i << ") " << consumibles[i]->get_name();
    }
    void inventory::show_weap()
    {
        for (int i = 0; i < num_wea; i++)
            std::cout << "(" << i << ") " << weapons[i]->get_name();
    }
    void inventory::show_cost()
    {
        for (int i = 0; i < num_equip; i++)
            std::cout << "(" << i << ") " << costumes[i]->get_name();
    }

    inventory::~inventory()
    {
        for (int i = 0; i < num_con; i++)
            delete consumibles[i];
        delete[] consumibles;
        for (int i = 0; i < num_wea; i++)
            delete weapons[i];
        delete[] weapons;
        for (int i = 0; i < num_equip; i++)
            delete costumes[i];
        delete[] costumes;
    }

    class Combat {
    private:
        int* turn;
        std::string* n_turn;
        int combat_size;
        int position;
        int players_size;
        int enemies_size;
        int num_of_turns;
        int const_size;//for defeated players

        bool playerturn;
        bool escape;
        bool playerdefeated;
        bool enemydefeated;
        std::string* weapon_table;

    public:
        Combat();
        Combat(character[], enemy enemies[], int players_team, int enemies_team, std::string[], int, table_element&, inventory&);
        virtual ~Combat();

        void put_speed(character players[], enemy enemies[]);
        void sort_speed();
        void show_array();

        void actualize_speed(character players[], enemy enemies[]);

        void evaluate_hp(character players[], enemy enemies[]);

        void show_data(character players[], enemy[]);
        void show_targets(character players[], enemy enemies[], int& targ); //view all targets available
        void select_ability(character players[], int& pos, int point_ro, bool valid); //view our abilities
        
        void change_array();
        void set_state(character players[], enemy[]);
        void search_turn(character players[], enemy[]);
        void If_dead(character players[], enemy enemies[], int pos, int E_P);
        
        void initCombat(character players[], enemy enemies[], table_element&, inventory&);
        void remove(character players[], enemy enemies[], int n);
        friend class character;
        friend class enemy;
    };

    Combat::Combat() {
        n_turn = 0;
        playerturn = false;
        escape = false;
        playerdefeated = false;
        enemydefeated = false;
        position = 0;
        num_of_turns = 0;
        players_size = 1;
        enemies_size = 1;
        combat_size = 0;
        const_size = 0;
        turn = 0;

    }
    Combat::Combat(character players[], enemy enemies[], int players_team, int enemies_team, std::string table_w[], int num, table_element& table, inventory& inven) {
        playerturn = false;
        escape = false;
        playerdefeated = false;
        enemydefeated = false;
        position = 0;
        num_of_turns = 0;
        players_size = players_team;
        enemies_size = enemies_team;
        weapon_table = new std::string[num];
        for (int i = 0; i < 6; i++)
            weapon_table[i] = table_w[i];
        put_speed(players, enemies);
        initCombat(players, enemies, table, inven);
    }
    Combat::~Combat() {
        delete[]turn;
        delete[] weapon_table;
        delete[] n_turn;
    }

    //put the speed values of enemies and players into the array "turn"
    void Combat::put_speed(character players[], enemy enemies[]) {
        combat_size = players_size + enemies_size;
        turn = new int[combat_size];
        n_turn = new std::string[combat_size];
        int n = 0;
        while (n < combat_size) {
            for (int i = 0; i < players_size; i++) {
                *(turn + n) = players[i].act_stats.get_stat_value(6);
                *(n_turn + n) = players[i].name;
                n++;
            }
            for (int j = 0; j < enemies_size; j++) {
                *(turn + n) = enemies[j].act_statdistic.get_stat_value(6);
                *(n_turn + n) = enemies[j].name;
                n++;
            }
        }
        sort_speed();
    }

    void Combat::actualize_speed(character players[], enemy enemies[])
    {
        int n = 0;
        while (n < combat_size) {
            for (int i = 0; i < players_size; i++) {
                *(turn + n) = players[i].act_stats.get_stat_value(6);
                *(n_turn + n) = players[i].name;
                n++;
            }
            for (int j = 0; j < enemies_size; j++) {
                *(turn + n) = enemies[j].act_statdistic.get_stat_value(6);
                *(n_turn + n) = enemies[j].name;
                n++;
            }
        }
        sort_speed();
        int c = num_of_turns;
        while (c > combat_size)
            c = c / combat_size;
        for (int i = 0; i < c; i++)
            change_array();
    }

    void Combat::sort_speed() {
        int key = 0, i, j;
        std::string key2;//selection sort 
        for (i = 1; i < combat_size; i++) {
            key = *(turn + i);
            key2 = *(n_turn + i);
            j = i - 1;

            while (j >= 0 && *(turn + j) < key) {
                *(turn + j + 1) = *(turn + j);
                *(n_turn + j + 1) = *(n_turn + j);
                j = j - 1;
            }
            *(turn + j + 1) = key;
            *(n_turn + j + 1) = key2;
        }
    }


    void Combat::show_array() {
        for (int i = 0; i < combat_size; i++)
            std::cout << *(n_turn + i) << "\t";
        std::cout << "\n";
    }

    void Combat::change_array() { //put the first value at the end of the array; 
        int copy = *(turn + 0);
        std::string copy2 = *(n_turn + 0);
        for (int i = 0; i < combat_size - 1; i++) {
            *(n_turn + i) = *(n_turn + i + 1);
            *(turn + i) = *(turn + i + 1);
        }
        *(turn + combat_size - 1) = copy;
        *(n_turn + combat_size - 1) = copy2;
    }

    void Combat::show_data(character players[], enemy enemies[])
    {
        for (int i = 0; i < players_size; i++)
            players[i].show_stats_in_combat();
        for (int i = 0; i < enemies_size; i++)
            enemies[i].show_in_combat();
    }

    void Combat::search_turn(character players[], enemy enemies[]) {
        int turn_of = *(turn + 0);
        std::string turn_of_2 = *(n_turn + 0);
        for (int i = 0; i < players_size; i++)
            if (turn_of == players[i].act_stats.get_stat_value(6) && turn_of_2 == players[i].name) { //find where the first value of "turn" in the array "players"
                position = i;
                playerturn = true;
                break;
            }
        for (int j = 0; j < enemies_size; j++)
            if (turn_of == enemies[j].act_statdistic.get_stat_value(6) && turn_of_2 == enemies[j].name) {
                position = j;
                playerturn = false;
                break;
            }
        change_array();
    }

    void Combat::select_ability(character players[], int& pos, int point_ro, bool valid){ //point_ro = .point_role
        std::cout << "choose ability\n\n";
        for (int i = 0; i < players[position].get_roles(0).get_size(); i++)
            std::cout << "(" << i << ")  " << players[position].roles[players[position].point_role[point_ro]].get_ability(i).get_name() << " cost: " << players[position].roles[players[position].point_role[point_ro]].get_ability(i).get_consume() << "\n";

        while (valid == false) {
            std::cin >> pos;
            if (players[position].act_stats.get_stat_value(1) < players[position].roles[players[position].point_role[point_ro]].get_ability(pos).get_consume())
                std::cout << "not enough magic points\n";
            else
               valid = true;
        }
    }
    
    void Combat::show_targets(character players[], enemy enemies[], int& targ) { //show the targets that you can attack
        std::cout << "choose the objetive\n";
        for (int i = 0; i < enemies_size; i++) {
            std::cout << "(" << i << ") " << "enemy: " << enemies[i].name << "\n";
        }
        for (int j = enemies_size; j < combat_size; j++) {
            std::cout << "(" << j << ") " << "player: " << players[combat_size - j - 1].name << "\n";
        }
		for (int k=combat_size; k<const_size;k++){
			std::cout<<"("<<k<<") "<<"defeated: " << players[(players_size-1)+(const_size-k)].name<<"\n";
		}
		
        std::cout << "(" << const_size << ") back:" << "\n";
        std::cin >>targ;
    }
    
    void Combat::If_dead(character players[], enemy enemies[], int pos, int E_P){ 
        switch (E_P){ // (E_P=0)= ENEMY (E_P=1) =PLAYER 
        case 0:    
            if(enemies[pos].act_statdistic.get_stat_value(0) == 0){//if player is dead
                std::cout << "enemy: " << enemies[pos].name << " defeated\n";
                enemydefeated = true;
                for (int j = 0; j < players_size; j++) {
                    players[j].set_experience_entity(enemies[pos].get_experience());
                    players[j].set_experience_class(enemies[pos].get_experience_class());
                    actualize_speed(players, enemies);
                }
                remove(players, enemies, pos);
            }
            break;
        case 1:
            if(players[pos].act_stats.get_stat_value(0) == 0){ //if player is dead
                std::cout << "player: " << players[pos].name << " defeated\n";
                playerdefeated = true;
                remove(players, enemies, pos);
            }
            break;
        }
    }
    
    void Combat::initCombat(character players[], enemy enemies[], table_element& table, inventory &inven) {
        std::cout << "turn based combat\n";

        int choice = 0;
        int second_choice = 0;
        int third_choice = 0;
        int order = 0;

        ability aux;
        weapon auxw;
        bool valid = false;
        while (!escape || enemies_size >= 0 || players_size >= 0) {
            evaluate_hp(players, enemies);
            show_array();
            show_data(players, enemies);
            search_turn(players, enemies);

            std::string id_defend="0";

            num_of_turns++;

            valid = false;

            std::cout << "\n";


            if (playerturn && enemies_size != 0 && players_size != 0) { //turn of players
                do {
                    if (id_defend == players[position].get_name())
                    {
                        players[position].act_stats.set_v_value(2, players[position].act_stats.get_stat_value(2) /2);
                        id_defend = "0";
                    }
                    
                    valid = false;
                    choice = 0;
                    second_choice = 0;
                    third_choice = 0;
                    std::cout << "turn of player: " << players[position].name << "\n";
                    std::cout << "(1) attack\n(2) ability for\n(3) ability for second class\n(4) defend\n(5) show_stats\n(6) items\n(7) escape" << "\n";
                    std::cin >> choice;
                    switch (choice) { //actions
                    case 1://attack
                            
                        show_targets(players, enemies, second_choice); //targets

                        if (second_choice < enemies_size) {

                            enemies[second_choice].take_damage(players[position].act_stats.get_stat_value(2), aux, table, players[position].get_wep_f());

                            If_dead(players, enemies, second_choice, 0); //if enemy is dead
                        }
                            
                        if (second_choice >= enemies_size && second_choice < combat_size) { //attack player
                            int min = combat_size - second_choice - 1;
                            std::cout << min;

                            players[min].take_damage(players[position].act_stats.get_stat_value(2), aux);

                            If_dead(players, enemies, min, 1); //if player is dead
                        }
                        break;
                            
                    case 2:// ability for primal class
                        select_ability(players, second_choice, 0, valid); //select ability point_ro= point_role

                        sshow_targets(players, enemies, third_choice); //targets
                            
                        if (third_choice < enemies_size) {
                            players[position].rest_mp(second_choice, 0);
                            if (players[position].get_fisical_magical(second_choice, 0) == true)
                                enemies[third_choice].take_damage(players[position].act_stats.get_stat_value(2), players[position].roles[players[position].point_role[0]].get_ability(second_choice), table, players[position].get_wep_f());
                            if (players[position].get_fisical_magical(second_choice, 0) == false)
                                enemies[third_choice].take_damage(players[position].act_stats.get_stat_value(4), players[position].roles[players[position].point_role[0]].get_ability(second_choice), table, players[position].get_wep_f());

                            If_dead(players, enemies, third_choice, 0); //if enemy is dead
                            
                        }
                            
                        else if (third_choice >= enemies_size && third_choice < combat_size) { //attack player
                            players[position].rest_mp(second_choice, 0);
                            int min = combat_size - third_choice - 1;
                            std::cout << min;
                            if (players[position].get_fisical_magical(second_choice, 0) == true)
                                players[min].take_damage(players[position].act_stats.get_stat_value(2), players[position].roles[players[position].point_role[0]].get_ability(second_choice));
                            if (players[position].get_fisical_magical(second_choice, 0) == false)
                                players[min].take_damage(players[position].act_stats.get_stat_value(2), players[position].roles[players[position].point_role[0]].get_ability(second_choice));
                            players[min].buff_debuff();
                            
                            If_dead(players, enemies, min, 1); //if player is dead
                        }

                        if(third_choice >=combat_size && third_choice < const_size){ //for revive a player
                            //it need to be fixed
                            players[position].rest_mp(second_choice, 0);
                            int min = (players_size-1)+(const_size-third_choice);
                            std::cout << min;
                            if (players[position].get_fisical_magical(second_choice, 0) == true)
                                players[min].take_damage(players[position].act_stats.get_stat_value(2), players[position].roles[players[position].point_role[0]].get_ability(second_choice));
                            if (players[position].get_fisical_magical(second_choice, 0) == false)
                                players[min].take_damage(players[position].act_stats.get_stat_value(2), players[position].roles[players[position].point_role[0]].get_ability(second_choice));
                            players[min].buff_debuff();
                            //

                            if(players[min].act_stats.get_stat_value(0) >= 0){ //revive
                                std::cout<<"return to combat: "<<players[min].name<<"\n"; 
                                combat_size++;
                                players_size++;
                                sort_speed();
                            }
                        }    
                        break;
                    case 3://atack with second class
                        select_ability(players, second_choice, 1, valid); //select ability point_ro= point_role
                        
                        show_targets(players, enemies, third_choice);//targets
                            
                        if (third_choice < enemies_size) {
                            players[position].rest_mp(second_choice, 1);
                            if (players[position].get_fisical_magical(second_choice, 1) == true)
                                enemies[third_choice].take_damage(players[position].act_stats.get_stat_value(2), players[position].roles[players[position].point_role[1]].get_ability(second_choice), table, players[position].get_wep_f());
                            if (players[position].get_fisical_magical(second_choice, 1) == false)
                                enemies[third_choice].take_damage(players[position].act_stats.get_stat_value(4), players[position].roles[players[position].point_role[1]].get_ability(second_choice), table, players[position].get_wep_f());

                            If_dead(players, enemies, third_choice, 0); //if enemy is dead
                        }
                            
                        if (third_choice >= enemies_size && third_choice < combat_size) { //attack player
                            players[position].rest_mp(second_choice, 1);
                            int min = combat_size - third_choice - 1;
                            std::cout << min;
                            if (players[position].get_fisical_magical(second_choice, 1) == true)
                                players[min].take_damage(players[position].act_stats.get_stat_value(2), players[position].roles[players[position].point_role[1]].get_ability(second_choice));
                            if (players[position].get_fisical_magical(second_choice, 1) == false)
                                players[min].take_damage(players[position].act_stats.get_stat_value(2), players[position].roles[players[position].point_role[1]].get_ability(second_choice));
                            players[min].buff_debuff();
                            
                            If_dead(players, enemies, min, 1); //if player is dead
                        }

                        break;     
                    case 4://defend
                        id_defend = players[position].get_name();
                        players[position].act_stats.set_v_value(2, players[position].act_stats.get_stat_value(2) * 2);
                        std::cout << players[position].get_name() << " defends\n";
                        break;
                    case 5://show stats
                        std::cout << players[position].get_name() << "\n";
                        players[position].act_stats.show_data();
                        players[position].act_stats.show_state();
                        choice = -1;
                        break;
                    case 6:
                        std::cout << "select item\n\n";
                        inven.show_con();
                        std::cin >> second_choice;
                        
                        show_targets(players, enemies, third_choice);//targets
                            
                        if (third_choice < enemies_size && third_choice >0) {
                            inven.use_item_enemy(second_choice, enemies[third_choice], table);
                            
                            If_dead(players, enemies, third_choice, 0); //if enemy is dead
                        }
                        else if (third_choice >= enemies_size && third_choice < combat_size)
                        {
                            int min = combat_size - third_choice - 1;
                            inven.use_item(second_choice, players[min]);
                            
                            If_dead(players, enemies, min, 1); //if player is dead
                        }
                    
                    case 7://escape
                        escape = true;
                        break;
                    }
                } while ((second_choice == const_size || third_choice == const_size) && choice != 4 && enemies_size != 0);
                players[position].buff_debuff();
                players[position].set_turn_state_minus();
            }
            else if (!playerturn && enemies_size != 0 && players_size != 0)
            { //turn of enemies
                std::cout << "turn of enemy: " << enemies[position].name << "\n";
                std::cout << "enemy attacks to: ";
                int action = rand() % 2;
                order = rand() % players_size; //choose the player

                std::cout << players[order].name << "\n";

                if (action == 0)
                    players[order].take_damage(enemies[position].act_statdistic.get_stat_value(2), aux);//damage
                else if (action == 1)
                {
                    int si = rand() % enemies[position].num_ability;
                    if (enemies[position].get_fisical_magical(si) == 'n' && (enemies[position].act_statdistic.get_stat_value(1) > enemies[position].get_ability(si).get_consume()))
                    {
                        if (enemies[position].benefic_ability_election(si)) {
                            order = rand() % enemies_size;
                            enemies[order].take_damage(enemies[position].act_statdistic.get_stat_value(2), enemies[position].get_ability(si), table, auxw);
                        }
                        else
                            players[order].take_damage(enemies[position].act_statdistic.get_stat_value(2), enemies[position].get_ability(si));
                        enemies[position].rest_mp(si);
                    }
                    else
                        std::cout << "insuficient mp\n";
                    if (enemies[position].get_fisical_magical(si) == 'm' && (enemies[position].act_statdistic.get_stat_value(1) > enemies[position].get_ability(si).get_consume()))
                    {
                        if (enemies[position].benefic_ability_election(si)) {
                            order = rand() % enemies_size;
                            enemies[order].take_damage(enemies[position].act_statdistic.get_stat_value(4), enemies[position].get_ability(si), table, auxw);
                        }
                        else
                            players[order].take_damage(enemies[position].act_statdistic.get_stat_value(4), enemies[position].get_ability(si));
                        enemies[position].rest_mp(si);
                    }
                    else
                        std::cout << "insuficient mp\n";
                }
                
                If_dead(players, enemies, order, 1); //if player is dead
                
                enemies[position].buff_debuff();
                enemies[position].turn_state_minus();

            }
            if (escape == true) {
                std::cout << "you run away!!!!\n";
                break;
            }
            std::cout << "\n";
            if (enemies_size == 0) {
                std::cout << "you win!\n";
                break;
            }
            if (players_size == 0) {
                std::cout << "you lost!\n";
                break;
            }
        }
    }

    void Combat::set_state(character players[], enemy enemies[])
    {
        for (int i = 0; i < enemies_size; i++) {
            enemies[i].buff_debuff();
            enemies[i].turn_state_minus();

        }
        for (int i = 0; i < players_size; i++) {
            players[i].buff_debuff();
            players[i].set_turn_state_minus();
        }
    }
    void Combat::evaluate_hp(character players[], enemy enemies[])
    {
        for (int i = 0; i < players_size; i++)
            if (players[i].act_stats.get_stat_value(0) == 0) {
                std::cout << players[i].name << " defeated\n";
                playerdefeated = true;
                remove(players, enemies, i);
            }
        for (int i = 0; i < enemies_size; i++)
            if (enemies[i].act_statdistic.get_stat_value(0) == 0) {
                std::cout << enemies[i].name << " defeated\n";
                enemydefeated = true;
                for (int j = 0; j < players_size; j++) {
                    players[j].set_experience_entity(enemies[i].get_experience());
                    players[j].set_experience_class(enemies[i].get_experience_class());
                }
                remove(players, enemies, i);
            }
    }
    void Combat::remove(character players[], enemy enemies[], int n) { //remove a player or enemy
        int sped = 0, x=0;
        std::string sped2, y;
        character p2;
        enemy p3;
        if (enemydefeated) {
            for (int i = 0; i < enemies_size; i++) //arary of enemies
                if (i == n) {
                    sped = enemies[i].act_statdistic.get_stat_value(6);
                    sped2 = enemies[i].name;
                    p3=enemies[i];
                    for (int j = i; j < enemies_size - 1; j++)
                        enemies[j] = enemies[j + 1];
                }
            enemies[enemies_size-1]=p3;
            
            for (int k = 0; k < combat_size; k++) //array of turns
                if (turn[k] == sped && n_turn[k] == sped2)
                    for (int l = k; l < combat_size - 1; l++) {
                        turn[l] = turn[l + 1];
                        n_turn[l] = n_turn[l + 1];
                    }
            enemies_size--;
            combat_size--;
            const_size--;

        }
        if (playerdefeated) {
            for (int i = 0; i < players_size; i++)//arary of players
                if (i == n) {
                    sped = players[i].act_stats.get_stat_value(6);
                    sped2 = players[i].name;
                    p2=players[i];
                    for (int j = i; j < players_size - 1; j++)
                        players[j] = players[j + 1];
                }
            players[players_size-1]=p2;
            
            for (int k = 0; k < combat_size; k++)//array of turns
                if (turn[k] == sped && n_turn[k] == sped2)
                    for (int l = k; l < combat_size - 1; l++) {
                        turn[l] = turn[l + 1];
                        n_turn[l] = n_turn[l + 1];
                    }
            turn[combat_size-1]=x; //put at the end of the array
			n_turn[combat_size-1]=y;
            players_size--;
            combat_size--;
        }
        enemydefeated = false;
        playerdefeated = false;
    }
}
