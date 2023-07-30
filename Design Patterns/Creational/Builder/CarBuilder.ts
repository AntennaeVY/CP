enum Engine {
  v8 = "V8 Engine",
  v6 = "V6 Engine",
}

class Car {
  seats: number;
  engine: Engine;
  tripComputer: boolean;
  GPS: boolean;
}

interface Builder {
  reset(): void;
  setSeats(number): this;
  setEngine(Engine): this;
  setTripComputer(): this;
  setGPS(): this;
}

class CarBuilder implements Builder {
  private car: Car = new Car();

  reset(): void {
    this.car = new Car();
  }

  setSeats(seatNumber: number): this {
    this.car.seats = seatNumber;
    return this;
  }

  setEngine(engineType: Engine): this {
    this.car.engine = engineType;
    return this;
  }

  setTripComputer(): this {
    this.car.tripComputer = true;
    return this;
  }

  setGPS(): this {
    this.car.GPS = true;
    return this;
  }

  getProduct(): Car {
    return this.car;
  }
}

class Director {
  makeSUV(builder: Builder) {
    builder.reset();

    builder.setEngine(Engine.v6).setSeats(6).setGPS().setTripComputer();
  }

  makeSportsCar(builder: Builder) {
    builder.reset();

    builder.setEngine(Engine.v8).setSeats(2).setGPS();
  }
}
