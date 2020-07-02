#pragma once

#include <iostream>
#include <math.h>
#include <string>
#include <cstdlib>
#include <time.h>
namespace rpg
{
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
        ~stats();
        friend class character;
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
        std::string state;
        int power;
        std::string element;
        std::string state_name;
        int consume;
    public:
        ability();
        ability(ability&);
        ability(std::string, std::string, int, table_element&, int, std::string, int);
        std::string get_name();
        std::string get_state();
        void modify_abilities(ability&);
        int get_power();
        int get_consume();
        std::string get_element();
        std::string get_state_name();
        void show_data();
        friend class character;
    };

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
    };

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
        weapon* equipment;
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
        void get_state_turn(ability&);
        void set_turn_state_minus();
        void rest_mp(int, int);

        void rest_all();

        char get_fisical_magical(int, int);

        void set_stats_for_weapon(std::string[], int);
        void redebuff();

        void show_act_stats();
        void equip(int, weapon&);
        void unequip(int);
        void modify_stats_equip_or_level();
        void modify_stats_buff_debuff();
        void set_experience_entity(float);
        void set_experience_class(float);

        void take_damage(int, ability&);

        void show_equipment();

        void change_class(int, int);
        void show_stats();
        void show_stats_in_combat();
        void show_for_elect();
        ~character();
        friend class Combat;
    };

    class enemy
    {
        std::string name;
        std::string state;
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

        char get_fisical_magical(int);
        void redebuff_();

        bool benefic_ability_election(int);

        void take_damage(int, ability&, table_element&, weapon&);
        ability& get_ability(int);
        void show_stats();
        void show_in_combat();
        ~enemy();
        friend class Combat;
    };

    class Combat {
    private:
        int* turn;
        std::string* n_turn;
        int combat_size;
        int position;
        int players_size;
        int enemies_size;
        int num_of_turns;

        bool playerturn;
        bool escape;
        bool playerdefeated;
        bool enemydefeated;
        std::string* weapon_table;

    public:
        Combat();
        Combat(character[], enemy enemies[], int players_team, int enemies_team, std::string[], int, table_element&);
        virtual ~Combat();

        void put_speed(character players[], enemy enemies[]);
        void sort_speed();
        void show_array();

        void actualize_speed(character players[], enemy enemies[]);

        void evaluate_hp(character players[], enemy enemies[]);

        void show_data(character players[], enemy[]);
        void change_array();
        void set_state(character players[], enemy[]);
        void search_turn(character players[], enemy[]);
        void initCombat(character players[], enemy enemies[], table_element&);
        void remove(character players[], enemy enemies[], int n);
        friend class character;
        friend class enemy;
    };

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

    ability::ability()
    {
        name = "empty";
        state = "000000";
        power = 0;
        element = "empty";
        state_name = "empty";
        consume = 0;
    }

    ability::ability(ability& o)
    {
        name = o.get_name();
        state = o.get_state();
        power = o.get_power();
        element = o.get_element();
        state_name = o.get_state_name();
        consume = o.get_consume();
    }

    ability::ability(std::string _name, std::string _state, int _power, table_element& _table, int pos, std::string name_state, int cons)
    {
        name = _name;
        state = _state;
        power = _power;
        element = _table.get_element(pos);
        state_name = name_state;
        consume = cons;
    }
    std::string ability::get_name()
    {
        return name;
    }
    void ability::modify_abilities(ability& o)
    {
        name = o.get_name();
        state = o.get_state();
        power = o.get_power();
        element = o.get_element();
        state_name = o.get_state_name();
        consume = o.get_consume();
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
    std::string ability::get_state()
    {
        return state;
    }
    std::string ability::get_state_name()
    {
        return state_name;
    }
    void ability::show_data()
    {
        std::cout << "Name: " << name << "\n";
        std::cout << "State: " << state_name << " code effect: " << state << "\n";
        std::cout << "Power: " << power << "\n";
        std::cout << "Element: " << element << "\n";
        std::cout << "consume: " << consume << "\n";
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
        equipment = nullptr;
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
        equipment = new weapon[equip];

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
        if (turn_state == 0) {
            state = "normal";
            code_state = "00000";
            redebuff();
        }
        else
            turn_state--;

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
        return equipment[pos];
    }
    char character::get_fisical_magical(int pos, int role)
    {
        int i = 0;
        while (roles[point_role[role]].get_ability(pos).get_state()[i] != '\0')
            i++;
        return roles[point_role[role]].get_ability(pos).get_state()[i - 1];
    }
    weapon& character::get_wep_f()
    {
        for (int i = 0; i < num_of_equip; i++)
            if (equipment[i].get_weapon_type() != "empty")
                return equipment[i];

    }
    void character::equip(int pos, weapon& new_weapon)
    {
        if (pos < num_of_equip && pos >= 0)
            equipment[pos].modify(new_weapon);
        character::modify_stats_equip_or_level();
    }
    void character::unequip(int pos)
    {
        if (pos < num_of_equip && pos >= 0)
            equipment[pos].modify_unequip();
        character::modify_stats_equip_or_level();
    }
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

    }
    void character::get_state_turn(ability& o)
    {
        int i = 0;
        while (o.get_state()[i] != '\0')
            i++;
        code_state = o.get_state();
        std::cout << (o.get_state()[i - 3] - '0') + (o.get_state()[i - 4] - '0') * 10;
        turn_state = (o.get_state()[i - 3] - '0') + (o.get_state()[i - 4] - '0') * 10;
    }

    /*
        |0000000 0000000 00 m|
    */
    void character::modify_stats_equip_or_level()
    {

        for (int i = 0; i < _stats.get_size(); i++) {
            _stats.set_v_value(i, constant[i] + (roles[point_role[0]].get_code_role(i) * _level.get_level()));
        }
        for (int i = 0; i < num_of_equip; i++)
            if (equipment[i].name != "empty") {
                for (int j = 0; j < _stats.get_size(); j++) {
                    _stats.sum_value(j, equipment[i].get_buff_debuff(j));
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
            while (o.get_state()[i] != '\0')
                i++;
            char mn = o.get_state()[--i];
            if (mn == 'n') {
                act_stats.sum_value(0, -((power + con) / act_stats.get_stat_value(3) * (o.get_power() / 10)));
                std::cout << name << " received " << o.get_name();
                if (-((power + con) / act_stats.get_stat_value(3) * (o.get_power() / 10)) != 0)
                    std::cout << " and took " << ((power + con) / act_stats.get_stat_value(3) * (o.get_power() / 10)) << " damage " << "\n";
            }
            if (mn == 'm') {
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
    void character::redebuff()
    {
        for (int i = 0; i < _stats.get_size(); i++)
            if (i != 0 && i != 1)
                act_stats.set_v_value(i, _stats.get_stat_value(i));

    }
    void character::show_equipment()
    {
        for (int i = 0; i < num_of_equip; i++)
            equipment[i].show_data();
    }
    void character::show_act_stats()
    {
        act_stats.show_data();
    }
    void character::set_stats_for_weapon(std::string l_weapon[], int num)
    {
        int sum = 0;
        for (int i = 0; i < num; i++)
            for (int j = 0; j < num_of_equip; j++)
                if (l_weapon[num] == equipment[num_of_equip].get_weapon_type())
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
        delete[]equipment;
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
        state = "normal";
        turn_state = 0;
    }
    enemy::enemy(const enemy& o) : stadistic(o.stadistic), act_statdistic(o.stadistic)
    {
        name = o.name;
        state = "nomal";
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
        state = "nomal";
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

    void enemy::get_state_turn(ability& o)
    {
        int i = 0;
        while (o.get_state()[i] != '\0')
            i++;
        state = o.get_state_name();
        code_state = o.get_state();
        turn_state = (o.get_state()[i - 3] - '0') + (o.get_state()[i - 4] - '0') * 10;
    }
    void enemy::turn_state_minus()
    {
        if (turn_state == 0) {
            state = "normal";
            code_state = "00000";
            redebuff_();
        }
        else
            turn_state--;

    }
    char enemy::get_fisical_magical(int pos)
    {
        int i = 0;
        while (abilities[pos].get_state()[i] != '\0')
            i++;
        return abilities[pos].get_state()[i - 1];
    }
    void enemy::rest_mp(int pos)
    {
        act_statdistic.set_v_value(1, abilities[pos].get_consume());
        if (act_statdistic.get_stat_value(1) < 0)
            act_statdistic.set_v_value(1, 0);
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
            while (o.get_state()[i] != '\0')
                i++;
            char mn = o.get_state()[--i];
            if (mn == 'n') {
                std::cout << name << " it was sent to him " << o.get_name() << " and receive " << ((power + con) * debi * debw) / act_statdistic.get_stat_value(3) * o.get_power();
                act_statdistic.sum_value(0, -(((power + con) * debi * debw) / act_statdistic.get_stat_value(3) * o.get_power()));
            }
            if (mn == 'm') {
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
        int i = 0;
        while (abilities[pos].get_state()[i] != ' ') {
            if (abilities[pos].get_state()[i] - '0' != 0)
                return true;
            i++;
        }
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
        turn = 0;

    }
    Combat::Combat(character players[], enemy enemies[], int players_team, int enemies_team, std::string table_w[], int num, table_element& table) {
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
        initCombat(players, enemies, table);
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

            while (j >= 0 && *(turn + j) > key) {
                *(turn + j + 1) = *(turn + j);
                *(n_turn + j + 1) = *(n_turn + j);
                j = j - 1;
            }
            *(turn + j + 1) = key;
            *(n_turn + j + 1) = key2;
        }
        for (int j = 0; j < combat_size / 2; j++) { //invert the sort
            int a = *(turn + j);
            std::string a2 = *(n_turn + j);
            *(turn + j) = *(turn + combat_size - 1 - j);
            *(turn + combat_size - 1 - j) = a;
            *(n_turn + j) = *(n_turn + combat_size - 1 - j);
            *(n_turn + combat_size - 1 - j) = a2;
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

    void Combat::initCombat(character players[], enemy enemies[], table_element& table) {
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

            num_of_turns++;

            valid = false;

            std::cout << "\n";


            if (playerturn && enemies_size != 0 && players_size != 0) { //turn of players
                do {
                    second_choice = 0;
                    third_choice = 0;
                    std::cout << "turn of player: " << players[position].name << "\n";
                    std::cout << "(1)attack\n(2)ability for\n(3)ability for second class\n(4)escape" << "\n";
                    std::cin >> choice;
                    switch (choice) { //actions
                    case 1://attack
                        std::cout << "choose the objetive\n";
                        for (int i = 0; i < enemies_size; i++) {
                            std::cout << "(" << i << ")" << "enemy: " << enemies[i].name << "\n";
                        }
                        for (int j = enemies_size; j < combat_size; j++) {
                            std::cout << "(" << j << ")" << "player: " << players[combat_size - j - 1].name << "\n";
                        }
                        std::cout << "(" << combat_size << ")back:" << "\n";
                        std::cin >> second_choice;


                        if (second_choice < enemies_size) {

                            enemies[second_choice].take_damage(players[position].act_stats.get_stat_value(2), aux, table, players[position].get_wep_f());



                            if (enemies[second_choice].act_statdistic.get_stat_value(0) == 0) { //if enemy is dead
                                std::cout << "enemy: " << enemies[second_choice].name << " defeated\n";
                                enemydefeated = true;
                                for (int j = 0; j < players_size; j++) {
                                    players[j].set_experience_entity(enemies[second_choice].get_experience());
                                    players[j].set_experience_class(enemies[second_choice].get_experience_class());
                                    actualize_speed(players, enemies);
                                }
                                remove(players, enemies, second_choice);
                                enemydefeated = false;
                            }
                        }
                        if (second_choice >= enemies_size && second_choice < combat_size) { //attack player
                            int min = combat_size - second_choice - 1;
                            std::cout << min;

                            players[min].take_damage(players[position].act_stats.get_stat_value(2), aux);


                            if (players[min].act_stats.get_stat_value(0) == 0) {// player is dead
                                std::cout << "player: " << players[min].name << " defeated\n";
                                playerdefeated = true;
                                remove(players, enemies, min);
                                playerdefeated = false;
                            }
                        }
                        break;
                    case 2:// ability for primal class
                        std::cout << "choose ability\n\n";

                        for (int i = 0; i < players[position].get_roles(0).get_size(); i++)
                            //if (players[position].act_stats.get_stat_value(1) < players[position].roles[players[position].point_role[0]].get_ability(i).get_consume())
                            std::cout << "(" << i << ")  " << players[position].roles[players[position].point_role[0]].get_ability(i).get_name() << " cost: " << players[position].roles[players[position].point_role[0]].get_ability(i).get_consume() << "\n";
                        while (valid == false) {
                            std::cin >> second_choice;
                            if (players[position].act_stats.get_stat_value(1) < players[position].roles[players[position].point_role[0]].get_ability(second_choice).get_consume())
                                std::cout << "not enough magic points\n";
                            else
                                valid = true;

                        }

                        std::cout << "choose the objetive\n";
                        for (int i = 0; i < enemies_size; i++) {
                            std::cout << "(" << i << ")" << "enemy: " << enemies[i].name << "\n";
                        }
                        for (int j = enemies_size; j < combat_size; j++) {
                            std::cout << "(" << j << ")" << "player: " << players[combat_size - j - 1].name << "\n";
                        }
                        std::cout << "(" << combat_size << ")back:" << "\n";
                        std::cin >> third_choice;
                        if (third_choice < enemies_size) {
                            players[position].rest_mp(second_choice, 0);
                            if (players[position].get_fisical_magical(second_choice, 0) == 'n')
                                enemies[third_choice].take_damage(players[position].act_stats.get_stat_value(2), players[position].roles[players[position].point_role[0]].get_ability(second_choice), table, players[position].get_wep_f());
                            if (players[position].get_fisical_magical(second_choice, 0) == 'm')
                                enemies[third_choice].take_damage(players[position].act_stats.get_stat_value(4), players[position].roles[players[position].point_role[0]].get_ability(second_choice), table, players[position].get_wep_f());

                            if (enemies[third_choice].act_statdistic.get_stat_value(0) == 0) { //if enemy is dead
                                std::cout << "enemy: " << enemies[third_choice].name << " defeated\n";
                                enemydefeated = true;
                                for (int j = 0; j < players_size; j++) {
                                    players[j].set_experience_entity(enemies[third_choice].get_experience());
                                    players[j].set_experience_class(enemies[third_choice].get_experience_class());
                                    actualize_speed(players, enemies);

                                }
                                remove(players, enemies, third_choice);
                                enemydefeated = false;
                            }
                        }
                        else if (third_choice >= enemies_size && third_choice < combat_size) { //attack player
                            players[position].rest_mp(second_choice, 0);
                            int min = combat_size - third_choice - 1;
                            std::cout << min;
                            if (players[position].get_fisical_magical(second_choice, 0) == 'n')
                                players[min].take_damage(players[position].act_stats.get_stat_value(2), players[position].roles[players[position].point_role[0]].get_ability(second_choice));
                            if (players[position].get_fisical_magical(second_choice, 0) == 'm')
                                players[min].take_damage(players[position].act_stats.get_stat_value(2), players[position].roles[players[position].point_role[0]].get_ability(second_choice));
                            players[min].modify_stats_buff_debuff();
                            if (players[min].act_stats.get_stat_value(0) == 0) {// player is dead
                                std::cout << "player: " << players[min].name << " defeated\n";
                                playerdefeated = true;
                                remove(players, enemies, min);
                                playerdefeated = false;
                            }
                        }

                        break;
                    case 3://atack with second class
                        std::cout << "choose ability\n\n";
                        for (int i = 0; i < players[position].get_roles(0).get_size(); i++)
                            //if (players[position].act_stats.get_stat_value(1) < players[position].roles[players[position].point_role[1]].get_ability(i).get_consume())
                            std::cout << "(" << i << ")  " << players[position].roles[players[position].point_role[1]].get_ability(i).get_name() << " cost:  " << players[position].roles[players[position].point_role[1]].get_ability(i).get_consume() << "\n";
                        while (valid == false) {
                            std::cin >> second_choice;
                            if (players[position].act_stats.get_stat_value(1) < players[position].roles[players[position].point_role[1]].get_ability(second_choice).get_consume())
                                std::cout << "not enough magic points\n";
                            else
                                valid = true;
                        }
                        std::cout << "choose the objetive\n";
                        for (int i = 0; i < enemies_size; i++) {
                            std::cout << "(" << i << ")" << "enemy: " << enemies[i].name << "\n";
                        }
                        for (int j = enemies_size; j < combat_size; j++) {
                            std::cout << "(" << j << ")" << "player: " << players[combat_size - j - 1].name << "\n";
                        }
                        std::cout << "(" << combat_size << ")back:" << "\n";
                        std::cin >> third_choice;
                        if (third_choice < enemies_size) {
                            players[position].rest_mp(second_choice, 1);
                            if (players[position].get_fisical_magical(second_choice, 1) == 'n')
                                enemies[third_choice].take_damage(players[position].act_stats.get_stat_value(2), players[position].roles[players[position].point_role[1]].get_ability(second_choice), table, players[position].get_wep_f());
                            if (players[position].get_fisical_magical(second_choice, 1) == 'm')
                                enemies[third_choice].take_damage(players[position].act_stats.get_stat_value(4), players[position].roles[players[position].point_role[1]].get_ability(second_choice), table, players[position].get_wep_f());

                            if (enemies[third_choice].act_statdistic.get_stat_value(0) == 0) { //if enemy is dead
                                std::cout << "enemy: " << enemies[third_choice].name << " defeated\n";
                                enemydefeated = true;
                                for (int j = 0; j < players_size; j++) {
                                    players[j].set_experience_entity(enemies[third_choice].get_experience());
                                    players[j].set_experience_class(enemies[third_choice].get_experience_class());
                                    actualize_speed(players, enemies);
                                }
                                remove(players, enemies, third_choice);
                                enemydefeated = false;
                            }
                        }
                        if (third_choice >= enemies_size && third_choice < combat_size) { //attack player
                            players[position].rest_mp(second_choice, 1);
                            int min = combat_size - third_choice - 1;
                            std::cout << min;
                            if (players[position].get_fisical_magical(second_choice, 1) == 'n')
                                players[min].take_damage(players[position].act_stats.get_stat_value(2), players[position].roles[players[position].point_role[1]].get_ability(second_choice));
                            if (players[position].get_fisical_magical(second_choice, 1) == 'm')
                                players[min].take_damage(players[position].act_stats.get_stat_value(2), players[position].roles[players[position].point_role[1]].get_ability(second_choice));
                            players[min].modify_stats_buff_debuff();
                            if (players[min].act_stats.get_stat_value(0) == 0) {// player is dead
                                std::cout << "player: " << players[min].name << " defeated\n";
                                playerdefeated = true;
                                remove(players, enemies, min);
                                playerdefeated = false;
                            }
                        }

                        break;
                    case 4://escape
                        escape = true;
                        break;
                    }

                } while (second_choice == enemies_size && choice != 1 && enemies_size != 0);
                players[position].modify_stats_buff_debuff();
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
                if (players[order].act_stats.get_stat_value(0) == 0) {// player is dead
                    std::cout << "player: " << players[order].name << " defeated\n";
                    playerdefeated = true;
                    remove(players, enemies, order);
                    playerdefeated = false;
                }
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
            players[i].modify_stats_buff_debuff();
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
        int sped = 0;
        std::string sped2;
        if (enemydefeated) {
            for (int i = 0; i < enemies_size; i++) //arary of enemies
                if (i == n) {
                    sped = enemies[i].act_statdistic.get_stat_value(6);
                    sped2 = enemies[i].name;
                    for (int j = i; j < enemies_size - 1; j++)
                        enemies[j] = enemies[j + 1];
                }

            for (int k = 0; k < combat_size; k++) //array of turns
                if (turn[k] == sped && n_turn[k] == sped2)
                    for (int l = k; l < combat_size - 1; l++) {
                        turn[l] = turn[l + 1];
                        n_turn[l] = n_turn[l + 1];
                    }
            enemies_size--;
            combat_size--;

        }
        if (playerdefeated) {
            for (int i = 0; i < players_size; i++)//arary of players
                if (i == n) {
                    sped = players[i].act_stats.get_stat_value(6);
                    sped2 = players[i].name;
                    for (int j = i; j < players_size - 1; j++)
                        players[j] = players[j + 1];
                }

            for (int k = 0; k < combat_size; k++)//array of turns
                if (turn[k] == sped && n_turn[k] == sped2)
                    for (int l = k; l < combat_size - 1; l++) {
                        turn[l] = turn[l + 1];
                        n_turn[l] = n_turn[l + 1];
                    }
            players_size--;
            combat_size--;
        }
        enemydefeated = false;
        playerdefeated = false;
    }
}