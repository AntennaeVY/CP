abstract class Button {
  abstract render(): void;
  abstract click(): void;
}

class WindowsButton implements Button {
  render(): void {
    console.log("%c[!]" + "Windows button rendered\n", "color: yellow");
  }

  click(): void {
    console.log("I click like a Windows button\n");
  }
}

class HTMLButton implements Button {
  render(): void {
    console.log("%c[!]" + "HTML button rendered\n", "color: yellow");
  }

  click(): void {
    console.log("I click like a HTML button\n");
  }
}

abstract class Dialog {
  render(): void {
    const myButton = this.createButton();

    myButton.render();
  }

  protected abstract createButton(): Button;
}

class WindowsDialog extends Dialog {
  protected createButton(): WindowsButton {
    return new WindowsButton();
  }
}

class WebDialog extends Dialog {
  protected createButton(): HTMLButton {
    return new HTMLButton();
  }
}

class Application {
  dialog!: Dialog;

  initialize(os: string): void {
    if (os == "Windows") {
      this.dialog = new WindowsDialog();
    } else if (os == "Web") {
      this.dialog = new WebDialog();
    } else {
      throw new Error(`The ${os} operative system is not supported yet`);
    }
  }

  start(): void {
    this.initialize("Windows");
    this.dialog.render();
  }
}

function main() {
  const app = new Application();

  app.start();
}

main();
