abstract class Shape {
  abstract render(): void;
  color: Color;

  constructor(color: Color) {
    this.color = color;
  }

  paint() {
    this.color.paint();
  }
}

abstract class Color {
  abstract paint(): void;
}

class Circle extends Shape {
  render(): void {
    console.log("Circle rendered...\n");
  }
}

class Triangle extends Shape {
  render(): void {
    console.log("Triangle rendered...\n");
  }
}

class Square extends Shape {
  render(): void {
    console.log("Square rendered...\n");
  }
}

class Red implements Color {
  paint(): void {
    console.log("Painting in red...\n");
  }
}

class Blue implements Color {
  paint(): void {
    console.log("Painting in blue...\n");
  }
}

function main() {
  const myRedCircle = new Circle(new Red());
  const myBlueTriangle = new Triangle(new Blue());
  const myBlueCircle = new Circle(new Blue());

  myRedCircle.render();
  myBlueTriangle.paint();
  console.log(myBlueCircle.color);
}

main();
