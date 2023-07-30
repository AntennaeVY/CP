abstract class Enemy {
  receiveAttack(): void {}
}

class ConcreteEnemy implements Enemy {
  receiveAttack(): void {
    console.log("Hit by an attack!");
  }
}

class EnemyArmorDecorator implements Enemy {
  private enemy: Enemy;

  constructor(enemy: Enemy) {
    this.enemy = enemy;
  }

  receiveAttack(): void {
    this.enemy.receiveAttack();
    console.log("... but luckily I had armor!");
  }
}

class EnemyEnchantmentDecorator implements Enemy {
  private enemy: Enemy;

  constructor(enemy: Enemy) {
    this.enemy = enemy;
  }

  receiveAttack(): void {
    this.enemy.receiveAttack();
    console.log("... but luckily I had enchantment!");
  }
}

function main() {
  const myEnemy = new ConcreteEnemy();

  myEnemy.receiveAttack();
  console.log("\n");

  const myEnemyWithArmor = new EnemyArmorDecorator(myEnemy);
  myEnemyWithArmor.receiveAttack();
  console.log("\n");

  const myEnemyWithArmorAndEnchantment = new EnemyEnchantmentDecorator(
    myEnemyWithArmor
  );
  myEnemyWithArmorAndEnchantment.receiveAttack();
}

main();
