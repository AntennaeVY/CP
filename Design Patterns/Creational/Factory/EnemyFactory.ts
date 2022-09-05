abstract class Entity {
  protected health: number = 100;
  public gameLogic(): void {
    console.log("Refreshing game logic...\n");
  }
}

abstract class EnemyEntity extends Entity {
  attack(): void {}
}

class Goomba extends Entity implements EnemyEntity {
  protected health: number = 100;
  attack(): void {
    console.log("I attack like a Goomba\n");
  }
}

class Koopa extends Entity implements EnemyEntity {
  protected health: number = 150;
  attack(): void {
    console.log("I attack like a Koopa\n");
  }
}

class Boo extends Entity implements EnemyEntity {
  protected health: number = 200;
  attack(): void {
    console.log("I attack like a Boo\n");
  }
}

abstract class EnemyFactory {
  createEnemy(): void {}
}

class RandomEnemyFactory implements EnemyFactory {
  createEnemy(): EnemyEntity {
    const randomNumber = Math.floor(Math.random() * 4);

    switch (randomNumber) {
      case 1:
        return new Goomba();
      case 2:
        return new Koopa();
      case 3:
        return new Boo();
      default:
        return new Goomba();
    }
  }
}

class GoombaEnemyFactory implements EnemyFactory {
  createEnemy(): Goomba {
    return new Goomba();
  }
}

function main() {
  const myFactory = new RandomEnemyFactory();
  const myEnemy = myFactory.createEnemy();

  console.log(myEnemy.gameLogic());
  console.log(myEnemy.attack());
}

main();
