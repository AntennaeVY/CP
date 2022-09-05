abstract class Transport {
  deliver(): void {}
}

class Truck implements Transport {
  deliver(): void {
    console.log("I'm delivering by land\n");
  }
}

class Ship implements Transport {
  deliver(): void {
    console.log("I'm delivering by sea\n");
  }
}

abstract class Logistics {
  abstract createTransport(): Transport;

  generalLogistics(): void {
    console.log("General logistics are done being prepared");
  }
}

class RoadLogistics extends Logistics {
  createTransport(): Truck {
    return new Truck();
  }
}

class SeaLogistics extends Logistics {
  createTransport(): Ship {
    return new Ship();
  }
}

function main() {
  const myRoadLogistics = new RoadLogistics();
  const mySeaLogistics = new SeaLogistics();

  const myTruck = myRoadLogistics.createTransport();
  const myShip = mySeaLogistics.createTransport();

  myRoadLogistics.generalLogistics();
  myTruck.deliver();
  myShip.deliver();
}

main();
