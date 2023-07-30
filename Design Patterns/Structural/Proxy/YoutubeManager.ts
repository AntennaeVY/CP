abstract class ThirdPartyYoutubeLib {
  listVideos() {}
  getVideoInfo(id: string) {}
  downloadVideo(id: string) {}
}

class ThirdPartyYoutubeClass implements ThirdPartyYoutubeLib {
  listVideos(): void {}
  getVideoInfo(id: string): void {}
  downloadVideo(id: string): void {}
}

class CachedYoutubeClassProxy implements ThirdPartyYoutubeLib {
  private service: ThirdPartyYoutubeLib;
  private listCache: string[] = [];
  private videoCache: string[] = [];

  constructor(service: ThirdPartyYoutubeLib) {
    this.service = service;
  }

  listVideos(): void {}
  getVideoInfo(id: string): void {}
  downloadVideo(id: string): void {}

  clearCache(): void {}
}

class YoutubeManager {
  private service: ThirdPartyYoutubeLib;

  constructor(service: ThirdPartyYoutubeLib) {
    this.service = service;
  }

  render(id: string): void {}
}

function main() {
  const myYoutubeManager = new YoutubeManager(
    new CachedYoutubeClassProxy(new ThirdPartyYoutubeClass())
  );
}

main();
