abstract class Chair {
  hasLegs(): boolean {
    return true;
  }

  abstract sitOn(): void;
}

abstract class Sofa {
  abstract isComfortable(): boolean;
  abstract capability(): number;
}

abstract class CoffeeTable {
  abstract isExpensive(): boolean;
}

class ModernChair extends Chair {
  sitOn(): void {
    console.log("Sat on modern chair\n");
  }
}

class ModernSofa implements Sofa {
  isComfortable(): boolean {
    return false;
  }

  capability(): number {
    return 2;
  }
}

class ModernCoffeeTable implements CoffeeTable {
  isExpensive(): boolean {
    return false;
  }
}

class VictorianChair extends Chair {
  sitOn(): void {
    console.log("Sat on victorian chair\n");
  }
}

class VictorianSofa implements Sofa {
  isComfortable(): boolean {
    return true;
  }

  capability(): number {
    return 5;
  }
}

class VictorianCoffeeTable implements CoffeeTable {
  isExpensive(): boolean {
    return true;
  }
}

abstract class FurnitureAbstractFactory {
  abstract createChair(): Chair;
  abstract createSofa(): Sofa;
  abstract createCoffeeTable(): CoffeeTable;
}

class ModernFurnitureFactory implements FurnitureAbstractFactory {
  createChair(): ModernChair {
    return new ModernChair();
  }

  createSofa(): ModernSofa {
    return new ModernSofa();
  }

  createCoffeeTable(): ModernCoffeeTable {
    return new ModernCoffeeTable();
  }
}

class VictorianFurnitureFactory implements FurnitureAbstractFactory {
  createChair(): VictorianChair {
    return new VictorianChair();
  }

  createSofa(): VictorianSofa {
    return new VictorianSofa();
  }

  createCoffeeTable(): VictorianCoffeeTable {
    return new VictorianCoffeeTable();
  }
}
