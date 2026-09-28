# PS4 Slopkit ESP32

A small ESP32-based local web server for hosting the **Aoi Slopkit** PS4 exploit chain.

The ESP32 provides a self-contained Wi-Fi access point and serves the complete Slopkit payload from LittleFS. No internet connection or separate PC/web server is required.

## Hardware

Tested with:

* ESP32, 4 MB flash
* LOLIN S2 Mini, 4 MB flash / 2 MB PSRAM

The S2 Mini is currently preferred because it provides noticeably better performance when serving the payload.

## Building

This is a PlatformIO project.

The exploit files live in:

```text
data/
```

The filesystem is LittleFS.

Build and upload the firmware using the PlatformIO controls in VS Code, then use:

**PlatformIO → Upload Filesystem Image**

to upload the contents of `data/`.

The project uses a custom 4 MB partition table with approximately 2.75 MB available for the filesystem.

## Usage

1. Power up the ESP32.

2. Connect the PS4 to the Wi-Fi network:

   ```text
   PS4 slopkit ESP32
   ```

3. The ESP32 uses:

   ```text
   192.168.4.1
   ```

4. Open the PS4 browser and navigate to:

   ```text
   http://192.168.4.1/
   ```

The Slopkit page will reject non-PS4 browsers, so seeing a *No PS4* message from a desktop browser is expected.

Follow the instructions presented by the Slopkit itself from that point onward.

## Notes

This is intended as a **local fallback host** for the Slopkit exploit chain. The ESP32 does not implement the exploit itself; it simply hosts the required web content locally.

The contents of `data/` are kept separate from the ESP32 firmware so the hosted chain can be updated without changing the server code.

## Credits

* **Aoi Slopkit** — original PS4 exploit chain
* **GamerHack** — original hosting/project work
* ESP32 port — this project
