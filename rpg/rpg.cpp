// rpg.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "RPG.h"

using namespace rpg;

int main()
{
    std::string elements[7] = { "fire","water","thunder","wind","light","dark","neutral" };
    table_element table(elements, 7);
    table.set_debilities("fire", "wind", "water");
    table.set_debilities("wind", "thunder", "fire");
    table.set_debilities("water", "fire", "thunder");
    table.set_debilities("thunder", "water", "wind");
    table.set_debilities("light", "dark", "dark");
    table.set_debilities("dark", "light", "light");
    table.show_table(); // fire water thunder wind light dark

    std::cout << "Aquí 1\n";
    std::string _global_stats[7] = { "life points","magic points","atack","defense","magic atack","magic defense","speed" };
    int _globalvalue[7] = { 0,0,0,0,0,0,0 };
    int _seth_stats[7] = { 40,30,20,20,15,15,20 };
    stats global(_global_stats, _globalvalue, 7);

    std::cout << "Aquí 2\n";
    //global.show_data();
    stats seth_stats(_global_stats, _globalvalue, 7);
    seth_stats.set_value(_seth_stats);
    seth_stats.show_data();

    std::cout << "Aquí 3\n";
    std::string type_of_weapon[6] = { "sword","spear","axe","bow","knife","crosier" };


    std::cout << "Aquí 4\n";
    level global_level;

    std::cout << "Aquí 5\n";
    global_level.add_exp(300);

    std::cout << "Aquí 6\n";
    ability sword_atack("sword atack", 40, table, 6, "normal", 0, "normal", 0, 0, 0, true);
    ability poison_level_1("poison level 1", 0, table, 6, "poison", 10, "poison", 0, -40, 5, false);
    ability explotion("explotion", 150, table, 6, "normal", 20, "normal", 0, 0, 0, true);
    ability down_atack("down atack", 0, table, 6, "normal", 30, "dwn atk", 2, -40, 3, true);

    std::cout << "Aquí 7\n";
    ability slash("slash", 70, table, 6, "normal", 0, "normal", 0, 0, 0, true);
    ability build_defense("build defense", 0, table, 6, "defense up", 10, "def up", 3, 30, 5, true);
    ability sword_destruction("sword destruction", 80, table, 6, "normal", 50, "normal", 0, 0, 0, true);
    ability build_atack("build atack", 0, table, 6, "atack_up", 60, "atk up", 2, 40, 3, true);

    std::cout << "Aquí 8\n";
    ability group_warrior[4];
    group_warrior[0] = slash;
    group_warrior[1] = build_defense;
    group_warrior[2] = sword_destruction;
    group_warrior[3] = build_atack;

    std::cout << "Aquí 9\n";
    ability cure_level("cure level 1", -20, table, 4, "cure hp", 15, "normal", 0, 0, 0, false);
    ability light_ball("light ball", 40, table, 4, "normal", 20, "normal", 0, 0, 0, false);
    ability defense_magic_up("build magic defense", 0, table, 6, "magic defense up", 25, "magic def up", 5, 40, 3, false);
    ability cure_level_2("cure level 2", -40, table, 4, "cure hp", 30, "normal", 0, 0, 0, false);

    std::cout << "Aquí 10\n";
    ability group_white_mage[4];
    group_white_mage[0] = cure_level;
    group_white_mage[1] = light_ball;
    group_white_mage[2] = defense_magic_up;
    group_white_mage[3] = cure_level_2;

    std::cout << "Aquí 11\n";
    ability group_freelancer[4];
    group_freelancer[0] = sword_atack;
    group_freelancer[1] = poison_level_1;
    group_freelancer[2] = explotion;
    group_freelancer[3] = down_atack;

    std::cout << "Aquí 12\n";
    item colgante("colgante ", "colgante bonito, sin utilidad");
    colgante.show_data();

    inventory invent;

    std::cout << "Aquí 13\n";
    int stats_sword[2] = { 10,-5 };
    std::string stats_name_sword[2] = { "atack","defense" };
    invent.push_weapon(2, stats_name_sword, stats_sword, "neutral", "normal", 0, 0, 0, "short sword", "a short sword", "sword");
    //sword swd(2,stats_name_sword, stats_sword, "neutral","normal",0,0,0,"short sword","a short sword") ;
    invent.weapons[0]->show_data();
    weapon* wea;
    wea = new weapon[6];
    for (int i = 0; i < 6; i++)
        wea[i].show_data();
    int level_to_use_freelancer[4] = { 10,20,30,40 };
    int level_to_use_warrior[4] = { 10,20,30,40 };
    int level_to_use_white_mage[4] = { 10,20,35,45 };

    std::cout << "Aquí 14\n";
    role freelancer("freelancer", "5555555", "abbbab", group_freelancer, global_level, level_to_use_freelancer, 4);
    freelancer.show_data();
    freelancer.display_habs();
    freelancer.add_level(3000);
    freelancer.display_habs();

    std::cout << "Aquí 15\n";
    role warrior("warrior", "6476345", "sasbdd", group_warrior, global_level, level_to_use_warrior, 4);
    role white_mage("white mage", "4734874", "cddcas", group_white_mage, global_level, level_to_use_white_mage, 4);

    std::cout << "Aquí 16\n";
    role* roles;
    roles = new role[3];
    roles[0] = freelancer;
    roles[1] = warrior;
    roles[2] = white_mage;

    std::cout << "Aquí 17\n";
    for (int i = 0; i < 3; i++)
    {
        roles[i].show_data();
    }

    stats f(seth_stats);
    f.set_v_value(0, 10000);
    f.set_v_value(6, 10000);
    f.show_data();
    seth_stats.show_data();


    character seth("seth", global, 3, global_level, roles, 6, _seth_stats);

    global.show_data();
    std::cout << "Aquí 18\n";
    seth.show_stats();
    std::cout << "\n\n";
    seth.change_class(2, 0);
    seth.show_stats();
    seth.set_experience_entity(3000);
    seth.show_stats();
    seth.change_class(1, 0);
    seth.show_stats();
    //swd.show_data();
    //seth.equip_weapon(0, swd);
    invent.equip_weapon(0, 0, seth);
    seth.show_stats();
    seth.set_experience_class(2000);
    seth.show_stats();


    std::cout << "Aquí 19\n";
    character gloria("gloria", global, 3, global_level, roles, 6, _seth_stats);
    gloria.set_experience_entity(3000);
    gloria.change_class(2, 0);
    seth.show_equipment();

    int crosier_stats[2] = {10,40};
    std::string crosier_name[2] = {"atack", "magic atack"};
    //weapon crosier(2, stats_name_sword, stats_sword, "neutral", " crosier", "a cleric´s crosier");
    invent.push_weapon(2, stats_name_sword, stats_sword, "neutral", "normal",0,0,0," crosier", "a cleric´s crosier","crosier");

    //gloria.equip(0, crosier);
    invent.equip_weapon(0, 1, gloria);

    std::cout << "Aquí 20\n";
    character* group;
    group = new character[2];
    group[0] = seth;
    group[1] = gloria;

    std::cout << "Aquí 21\n";
    group[0].show_stats();
    group[1].show_stats();

    group[0].rest_all();
    group[1].rest_all();

    group[0].show_act_stats();



    //GOBLIN CREATION

    int gob[7] = { 400, 100, 50, 50, 30,30,20 };
    stats go_l(_global_stats, gob, 7);

    ability atk("hit", 50, table, 6, "normal", 0, "normal", 0, 0, 0, true);
    ability poison_g("poison",  0, table, 6, "poison", 10, "poisoned",0,-40,5, true );
    ability h_crush("h_crush",  120, table, 6, "normal", 35, "normal",0,0,0, true);
    ability group_goblin[3];
    group_goblin[0] = atk;
    group_goblin[1] = poison_g;
    group_goblin[2] = h_crush;


    enemy globin("goblin", 100.0, 100.0, go_l, group_goblin, 3, table, 6);
    enemy goblin_2(globin);
    goblin_2.set_name("goblin 2");
    enemy goblin_3(globin);
    goblin_3.set_name("goblin 3");

    // WARRIOR CREATION

    int war[7] = { 800, 50, 140, 80, 30, 50, 60 };
    stats wa_l(_global_stats, war, 7);
    ability warrior_sword("warrior sword", 80, table, 6, "normal", 0, "normal",0,0,0, true);
    ability build_up("build up", 0, table, 6, "atk_up", 10, "atak_up", 2, 50, 4, true);
    ability break_rock("break_rock",  150, table, 6, "normal", 35, "normal",0,0,0, true);
    ability group_war[3];
    group_war[0] = warrior_sword;
    group_war[1] = build_up;
    group_war[0] = break_rock;

    enemy man_of_war("man of war", 300.0, 300.0, wa_l, group_war, 3, table, 5);
    enemy man_of_war_2(man_of_war);
    man_of_war_2.set_name("man of war 2");

    //GROUP ENEMY

    enemy* group_enemy;
    group_enemy = new enemy[5];
    group_enemy[0] = globin;
    group_enemy[1] = goblin_2;
    group_enemy[2] = goblin_3;
    group_enemy[3] = man_of_war;
    group_enemy[4] = man_of_war_2;
    Combat combat(group, group_enemy, 2, 5, type_of_weapon, 6, table, invent);


    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
