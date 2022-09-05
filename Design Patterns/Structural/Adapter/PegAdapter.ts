class RoundHole {
  private radius: number;

  constructor(radius: number) {
    this.radius = radius;
  }

  fits(peg: RoundPeg): boolean {
    return this.radius >= peg.getRadius();
  }
}

class RoundPeg {
  private radius: number;

  constructor(radius: number) {
    this.radius = radius;
  }

  getRadius(): number {
    return this.radius;
  }
}

class SquarePeg {
  private length: number;

  constructor(length: number) {
    this.length = length;
  }

  getLength() {
    return this.length;
  }
}

class SquarePegAdapter extends RoundPeg {
  private peg: SquarePeg;

  constructor(peg: SquarePeg) {
    super((peg.getLength() * Math.sqrt(2)) / 2);
    this.peg = peg;
  }
}

function main() {
  const myRoundHole = new RoundHole(10);
  const myRoundPeg = new RoundPeg(5);

  const mySquarePeg = new SquarePeg(6);
  const myAdapter = new SquarePegAdapter(mySquarePeg);

  console.log(myRoundHole.fits(myRoundPeg));
  console.log(myRoundHole.fits(myAdapter));
}

main();
