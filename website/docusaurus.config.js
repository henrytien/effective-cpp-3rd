// @ts-check

/** @type {import('@docusaurus/types').Config} */
const config = {
  title: 'Effective C++ 3rd Edition',
  tagline: '55 Specific Ways to Improve Your Programs and Designs',
  favicon: 'img/favicon.ico',

  url: 'https://henrytien.github.io',
  baseUrl: '/effective-cpp-3rd/',

  organizationName: 'henrytien',
  projectName: 'effective-cpp-3rd',

  onBrokenLinks: 'throw',
  onBrokenMarkdownLinks: 'warn',

  i18n: {
    defaultLocale: 'en',
    locales: ['en'],
  },

  presets: [
    [
      'classic',
      /** @type {import('@docusaurus/preset-classic').Options} */
      ({
        docs: {
          sidebarPath: './sidebars.js',
          editUrl: 'https://github.com/henrytien/effective-cpp-3rd/edit/master/website/',
        },
        blog: false,
        theme: {
          customCss: './src/css/custom.css',
        },
      }),
    ],
  ],

  themeConfig:
    /** @type {import('@docusaurus/preset-classic').ThemeConfig} */
    ({
      navbar: {
        title: 'Effective C++',
        items: [
          {
            type: 'docSidebar',
            sidebarId: 'mainSidebar',
            position: 'left',
            label: 'Items',
          },
          {
            href: 'https://github.com/henrytien/effective-cpp-3rd',
            label: 'GitHub',
            position: 'right',
          },
        ],
      },
      footer: {
        style: 'dark',
        links: [
          {
            title: 'Docs',
            items: [
              { label: 'Introduction', to: '/docs/' },
            ],
          },
          {
            title: 'More',
            items: [
              { label: 'GitHub', href: 'https://github.com/henrytien/effective-cpp-3rd' },
              { label: 'Buy the Book', href: 'http://www.amazon.com/Effective-Specific-Improve-Programs-Designs/dp/0321334876' },
            ],
          },
        ],
        copyright: `Copyright ${new Date().getFullYear()} henrytien. Built with Docusaurus.`,
      },
      prism: {
        theme: require('prism-react-renderer').themes.github,
        darkTheme: require('prism-react-renderer').themes.dracula,
        additionalLanguages: ['cpp'],
      },
    }),
};

module.exports = config;
