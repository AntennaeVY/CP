abstract class Device {
  isEnabled(): void {}
  enable(): void {}
  disable(): void {}
  getVolume(): void {}
  setVolume(): void {}
  getChannel(): void {}
  setChannel(): void {}
}

class Remote {
  private device: Device;

  constructor(device: Device) {
    this.device = device;
  }

  togglePower(): void {}
  volumeUp(): void {}
  volumeDown(): void {}
  channelUp(): void {}
  channelDown(): void {}
}

class AdvancedRemote extends Remote {
  mute(): void {}
}

class Television implements Device {
  isEnabled(): void {}
  enable(): void {}
  disable(): void {}
  getVolume(): void {}
  setVolume(): void {}
  getChannel(): void {}
  setChannel(): void {}
}

class Radio implements Device {
  isEnabled(): void {}
  enable(): void {}
  disable(): void {}
  getVolume(): void {}
  setVolume(): void {}
  getChannel(): void {}
  setChannel(): void {}
}

function main() {
  const myTelevision = new Television();
  const myRemote = new Remote(myTelevision);
}

main();
